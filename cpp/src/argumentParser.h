#include <string>
#include <unordered_map>
#include <vector>

class ArgumentParser
{
public:
  ArgumentParser(int argc, char **argv);
  bool hasFlag(const std::string &flag) const;
  std::string getValue(const std::string &key) const;
  void showHelp() const;
  std::string getInputFile() const;
  std::string getOutputFile() const;

private:
  std::unordered_map< std::string, bool > flags;
  std::unordered_map< std::string, std::string > values;
  std::string inputFile;
  std::string outputFile;
  void parseArguments(int argc, char **argv);
};