#include "TerseDecompresser.h"
#include "Constants.h"
#include "NonSpackDecompresser.h"
#include "SpackDecompresser.h"

#include <cstring>
#include <iostream>
#include <stdexcept>

std::unique_ptr< TerseDecompresser > TerseDecompresser::create(std::istream &inputStream, std::ostream &outputStream)
{
  TerseHeader header = TerseHeader::checkHeader(inputStream);
  auto reader = std::make_unique< TerseBlockReader >(inputStream);
  if (header.spackFlag)
  {
    return std::make_unique< SpackDecompresser >(inputStream, outputStream, std::move(reader), header);
  }
  else
  {
    return std::make_unique< NonSpackDecompresser >(inputStream, outputStream, std::move(reader), header);
  }
}

void TerseDecompresser::putChar(int x)
{
  if (x == 0)
  {
    if (hostFlag_ && textMode_ && variableFlag_)
    {
      endRecord();
    }
  }
  else
  {
    if (hostFlag_ && textMode_)
    {
      if (variableFlag_)
      {
        if (x == Tersedecompress::RECORDMARK)
        {
          endRecord();
        }
        else
        {
          record_.push_back(static_cast< char >(Tersedecompress::EbcToAsc[x - 1]));
        }
      }
      else
      {
        // Fixed record length
        record_.push_back(static_cast< char >(Tersedecompress::EbcToAsc[x - 1]));
        // If we hit the record length limit, end the record
        if (static_cast< int >(record_.size()) == recordLength_)
        {
          endRecord();
        }
      }
    }
    else
    {
      if (x == Tersedecompress::RECORDMARK)
      {
        if (variableFlag_)
        {
          endRecord();
        }
      }
      else
      {
        record_.push_back(static_cast< char >(x - 1));
      }
    }
  }
}

void TerseDecompresser::endRecord()
{
  if (variableFlag_ && !textMode_)
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

    // // Write it big-endian
    // unsigned char rdw[4];
    // rdw[0] = (lengthWithRDW >> 24) & 0xFF;
    // rdw[1] = (lengthWithRDW >> 16) & 0xFF;
    // rdw[2] = (lengthWithRDW >> 8) & 0xFF;
    // rdw[3] = lengthWithRDW & 0xFF;

    outputStream_.write(reinterpret_cast< const char * >(rdw), 4);
  }
  if (!record_.empty())
  {
    outputStream_.write(record_.data(), record_.size());
  }
  record_.clear();
  if (textMode_)
  {
    outputStream_.put('\n');
  }
}

void TerseDecompresser::close() 
{
  if (!record_.empty() || (textMode_ && variableFlag_))
  {
    endRecord();
  }
  outputStream_.flush();
}