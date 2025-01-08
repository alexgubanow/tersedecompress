#include "TerseDecompresser.h"

#include <cstdlib>
#include <fstream>
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>

void printUsageAndExit()
{
  std::cout << "Usage: tersedecompress <input file> <output file> [-b]\n\n"
            << "Decompress a file compressed using the terse program on z/OS.\n\n"
            << "Options:\n"
            << "  -b                Binary mode (no EBCDIC->ASCII conversion)\n"
            << "  -h, --help        Show this help message\n\n"
            << "When not in binary mode, the program attempts EBCDIC->ASCII conversion.\n"
            << "If <output file> is not provided in text mode, it defaults to <input file>.txt.\n"
            << std::endl;
  std::cout << "Version: 5 (C++ port)\n";
  std::exit(EXIT_SUCCESS);
}

int main(int argc, char *argv[])
{
  if (argc == 1)
  {
    printUsageAndExit();
  }

  std::string inputFileName;
  std::string outputFileName;
  bool textMode = true;
  bool helpRequested = false;

  // We’ll parse flags and arguments in a way similar to the Java parseArgs()
  //  - first non-flag is input file
  //  - second non-flag is output file
  //  - -b sets binary mode => textMode = false
  //  - -h/--help => show usage
  //  - anything extra => show usage
  int nonFlagCount = 0;
  for (int i = 1; i < argc; ++i)
  {
    std::string arg = argv[i];
    if (arg == "-h" || arg == "--help")
    {
      helpRequested = true;
    }
    else if (arg == "-b")
    {
      textMode = false;
    }
    else if (arg.rfind("-", 0) == 0)
    {
      helpRequested = true;
    }
    else
    {
      nonFlagCount++;
      if (nonFlagCount == 1)
      {
        inputFileName = arg;
      }
      else if (nonFlagCount == 2)
      {
        outputFileName = arg;
      }
      else
      {
        // more than 2 non-flag arguments => usage
        helpRequested = true;
      }
    }
  }

  // If help requested or missing required info, print usage
  if (helpRequested || nonFlagCount == 0)
  {
    printUsageAndExit();
  }
  // If we have input but no output and we're in text mode => default output = input + ".txt"
  if (nonFlagCount == 1 && textMode)
  {
    outputFileName = inputFileName + ".txt";
  }
  else if (nonFlagCount == 1 && !textMode)
  {
    // In binary mode, we must have an output file
    printUsageAndExit();
  }

  std::cout << "Input:  " << inputFileName << "\n";
  std::cout << "Output: " << outputFileName << "\n";
  std::cout << "Mode:   " << (textMode ? "Text" : "Binary") << std::endl;

  std::ifstream inStream(inputFileName, std::ios::binary);
  if (!inStream.is_open())
  {
    std::cerr << "Error: Unable to open input file: " << inputFileName << "\n";
    return EXIT_FAILURE;
  }
  std::ofstream outStream(outputFileName, std::ios::binary);
  if (!outStream.is_open())
  {
    std::cerr << "Error: Unable to open output file: " << outputFileName << "\n";
    return EXIT_FAILURE;
  }

  try
  {
    auto decompresser = TerseDecompresser::create(inStream, outStream);
    decompresser->setTextFlag(textMode);
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
