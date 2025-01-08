#ifndef TERSEDECOMPRESSER_H
#define TERSEDECOMPRESSER_H

#include "TerseBlockReader.h"
#include "TerseHeader.h"

#include <istream>
#include <memory>
#include <ostream>
#include <vector>

class TerseDecompresser
{
public:
  static std::unique_ptr< TerseDecompresser > create(std::istream &inputStream, std::ostream &outputStream);
  virtual ~TerseDecompresser() = default;
  virtual void decode() = 0;
  void setTextFlag(bool flag) { textMode_ = flag; }

protected:
  TerseDecompresser(std::istream &in, std::ostream &out): inputStream_(in), outputStream_(out) {}
  void putChar(int x);
  void endRecord();
  void close();
  bool hostFlag_ = false;     // HostFlag (header-based)
  bool variableFlag_ = false; // RecfmV (header-based)
  bool textMode_ = false;     // from user arg (-b vs. default)
  int recordLength_ = 0;       // from the TerseHeader
  std::vector< char > record_; // buffer for the current record
  std::istream &inputStream_;
  std::ostream &outputStream_;
  std::unique_ptr< TerseBlockReader > blockReader_;
};

#endif // TERSEDECOMPRESSER_H
