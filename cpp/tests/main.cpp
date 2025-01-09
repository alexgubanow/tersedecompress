#include "testHelpers.h"

#include <string>
#include "gtest/gtest.h"

int main(int argc, char **argv) {
  std::string command_line_arg(argc == 2 ? argv[1] : "./");
  testing::InitGoogleTest(&argc, argv);
  TestHelpers *testEnv = new TestHelpers(command_line_arg);
  TestHelpers::SetInst(testEnv);
  testing::AddGlobalTestEnvironment(testEnv);
  return RUN_ALL_TESTS();
}