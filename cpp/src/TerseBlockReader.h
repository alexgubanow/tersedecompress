#ifndef TERSEBLOCKREADER_H
#define TERSEBLOCKREADER_H

#include <istream>

class TerseBlockReader
{
public:
  explicit TerseBlockReader(std::istream &input);
  int getBlok();

private:
  std::istream &input_;
  int bitsAvailable_ = 0;
  int savedBits_ = 0;
};

#endif // TERSEBLOCKREADER_H
