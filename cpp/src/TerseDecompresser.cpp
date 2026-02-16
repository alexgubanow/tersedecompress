#include "TerseDecompresser.h"
#include "Constants.h"
#include "NonSpackDecompresser.h"
#include "SpackDecompresser.h"

#include <cstring>
#include <iostream>
#include <stdexcept>

std::unique_ptr< TerseDecompresser > TerseDecompresser::create(std::istream &inputStream, std::ostream &outputStream,
                                                               const DecompresserOptions &options)
{
  TerseHeader header = TerseHeader::parseHeader(inputStream);
  if (header.spackFlag)
  {
    return std::make_unique< SpackDecompresser >(inputStream, outputStream, header, options);
  }
  else
  {
    return std::make_unique< NonSpackDecompresser >(inputStream, outputStream, header, options);
  }
}

TerseDecompresser::~TerseDecompresser()
{
}

TerseDecompresser::TerseDecompresser(std::istream &in, std::ostream &out, const TerseHeader &header, const DecompresserOptions &options)
    : header_(header), options_(options), inputStream_(in), outputStream_(out)
{
  blockReader_ = std::make_unique< TerseBlockReader >(inputStream_);
  // Reserve enough space for the record buffer to avoid reallocations.
  // For variable-length records, we can have up to 32767 bytes.
  record_.reserve(header_.variableFlag ? 32767 : (header_.recordLength * 2));
}

void TerseDecompresser::putChar(int x)
{
  if (x == 0 && options_.textMode && header_.variableFlag == true)
  {
      endRecord();
  }
  else if (x == Tersedecompress::RECORDMARK && header_.variableFlag == true)
  {
    endRecord();
  }
  else
  {
    if (record_.capacity() == record_.size())
    {
      throw std::runtime_error("Record size exceeds expected maximum. File may be corrupted or not a valid Terse file.");
    }
    record_.push_back(options_.textMode ? static_cast< char >(Tersedecompress::EbcToAsc[x - 1])
                                        : static_cast< char >(x - 1));
    if (header_.variableFlag != true && static_cast< int >(record_.size()) == header_.recordLength)
    {
      endRecord();
    }
  }
}

void TerseDecompresser::endRecord()
{
  if (header_.variableFlag && !options_.textMode)
  {
    // Write a 4-byte Record Descriptor Word (RDW)
    // RDW = (record_.size() + 4) in high-order 2 bytes + low-order 2 bytes
    size_t lengthWithRDW = record_.size() + 4;
    // For MVS VB:
    //   bytes[0..1] = (16-bit) length of record
    //   bytes[2..3] = reserved (usually zero)
    unsigned char rdw[4];
    rdw[0] = static_cast< unsigned char >((lengthWithRDW >> 8) & 0xFF); // high-order length byte
    rdw[1] = static_cast< unsigned char >(lengthWithRDW & 0xFF);        // low-order length byte
    rdw[2] = 0x00;
    rdw[3] = 0x00;
    outputStream_.write(reinterpret_cast< const char * >(rdw), 4);
  }
  if (options_.textMode)
  {
    record_.push_back(0x0A);
  }
  if (record_.empty())
  {
    return;
  }
  {
    outputStream_.write(record_.data(), record_.size());
  }
  record_.clear();
}

void TerseDecompresser::close() 
{
  if (!record_.empty() || (options_.textMode && header_.variableFlag))
  {
    endRecord();
  }
  outputStream_.flush();
}