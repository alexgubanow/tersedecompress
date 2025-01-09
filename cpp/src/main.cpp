#include "TerseDecompresser.h"
#include "argumentParser.h"

#include <cstdlib>
#include <fstream>
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>

int main(int argc, char *argv[])
{
  ArgumentParser parser(argc, argv);

  if (parser.hasFlag("-h") || (parser.hasFlag("-b") == true && parser.getOutputFile().empty()))
  {
    std::cout << "Output filename must be given in binary mode.\n";
    parser.showHelp();
    return 0;
  }

  std::cout << "Input file: " << parser.getInputFile() << "\n";
  std::cout << "Output file: " << parser.getOutputFile() << "\n";
  std::cout << "Mode:   " << (parser.hasFlag("-b") ? "Binary" : "Text") << std::endl;

  std::ifstream inStream(parser.getInputFile(), std::ios::binary);
  if (!inStream.is_open())
  {
    std::cerr << "Error: Unable to open input file: " << parser.getInputFile() << "\n";
    return EXIT_FAILURE;
  }
  std::ofstream outStream(parser.getOutputFile(), std::ios::binary);
  if (!outStream.is_open())
  {
    std::cerr << "Error: Unable to open output file: " << parser.getOutputFile() << "\n";
    return EXIT_FAILURE;
  }

  try
  {
    auto decompresser = TerseDecompresser::create(inStream, outStream);
    decompresser->setTextFlag(parser.hasFlag("-b") == false);
    std::cout << "Decompressing...\n";
    decompresser->decode();
  }
  catch (const std::exception &ex)
  {
    std::cerr << "An error occurred: " << ex.what() << "\n";
    return EXIT_FAILURE;
  }

  std::cout << "Processing completed.\n";
  return EXIT_SUCCESS;
}
