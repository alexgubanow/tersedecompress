#include "testHelpers.h"
#include "../src/TerseDecompresser.h"

#include <cstring>

static std::string test_data_path = "./";

TestHelpers *TestHelpers::inst = nullptr;

void TestHelpers::DecompressAndVerify(const std::string &file, const std::string &ext, bool textMode)
{
  std::string tersed = test_data_path + "TERSED/" + file + "." + ext;
  std::string untersed = test_data_path + (textMode ? "ZOSTEXT/" : "ZOSBINARY/") + file;
  std::ifstream tersedStream(tersed, std::ios::binary);
  if (!tersedStream.is_open())
  {
    throw std::runtime_error("Could not open file: " + tersed);
  }
  std::ifstream expectedStream(untersed, std::ios::binary);
  if (!expectedStream.is_open())
  {
    throw std::runtime_error("Could not open file: " + untersed);
  }
  std::stringstream output(std::ios::in | std::ios::out | std::ios::binary);

  auto decomp = TerseDecompresser::create(tersedStream, output);
  decomp->setTextFlag(textMode);
  decomp->decode();

  output.seekg(0, std::ios::end);
  expectedStream.seekg(0, std::ios::end);

  size_t outputSize = output.tellg();
  size_t expectedStreamSize = expectedStream.tellg();

  ASSERT_EQ(outputSize, expectedStreamSize) << "Mismatch for " << tersed;
  output.seekg(0, std::ios::beg);
  expectedStream.seekg(0, std::ios::beg);

  const std::size_t BUFFER_SIZE = outputSize > 1048576 ? 1048576 : outputSize;
  std::vector< char > bufferA(BUFFER_SIZE + 1);
  std::vector< char > bufferB(BUFFER_SIZE + 1);
  while (!output.eof())
  {
    output.read(bufferA.data(), BUFFER_SIZE);
    expectedStream.read(bufferB.data(), BUFFER_SIZE);
    bufferA[output.gcount()] = '\0';
    bufferB[expectedStream.gcount()] = '\0';
    ASSERT_EQ(output.gcount(), expectedStream.gcount()) << "Mismatch for actual read of " << tersed << "\nExpected size "
                                                        << expectedStream.gcount() << " untersed size " << output.gcount();
    if (std::memcmp(bufferA.data(), bufferB.data(), output.gcount()) != 0)
    {
      std::cout << "Mismatch for " << tersed;
    }

    ASSERT_EQ(std::memcmp(bufferA.data(), bufferB.data(), output.gcount()), 0)
        << "Contents differ for " << file << " current position " << output.tellp();
  }
}
