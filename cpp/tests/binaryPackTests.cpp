#include "testHelpers.h"
#include <gtest/gtest.h>

TEST(BinaryPackTests, Test01_FBA_TXT) { TestHelpers::GetInst()->DecompressAndVerify("FB.A.TXT", "PACK", false); }

TEST(BinaryPackTests, Test02_FBAAA_TXT) { TestHelpers::GetInst()->DecompressAndVerify("FB.AAA.TXT", "PACK", false); }

TEST(BinaryPackTests, Test03_FBALICE29_TXT) { TestHelpers::GetInst()->DecompressAndVerify("FB.ALICE29.TXT", "PACK", false); }

TEST(BinaryPackTests, Test04_FBALPHABET_TXT)
{
  TestHelpers::GetInst()->DecompressAndVerify("FB.ALPHABET.TXT", "PACK", false);
}

TEST(BinaryPackTests, Test05_FBASYOU_LIK_TXT)
{
  TestHelpers::GetInst()->DecompressAndVerify("FB.ASYOULIK.TXT", "PACK", false);
}

TEST(BinaryPackTests, Test06_FBBIBLE_TXT) { TestHelpers::GetInst()->DecompressAndVerify("FB.BIBLE.TXT", "PACK", false); }

TEST(BinaryPackTests, Test07_FBCP_HTML) { TestHelpers::GetInst()->DecompressAndVerify("FB.CP.HTML", "PACK", false); }

TEST(BinaryPackTests, Test08_FBE_COLI) { TestHelpers::GetInst()->DecompressAndVerify("FB.E.COLI", "PACK", false); }

TEST(BinaryPackTests, Test09_FBFIELDS_C) { TestHelpers::GetInst()->DecompressAndVerify("FB.FIELDS.C", "PACK", false); }

TEST(BinaryPackTests, Test10_FBGRAMMAR_LSP) { TestHelpers::GetInst()->DecompressAndVerify("FB.GRAMMAR.LSP", "PACK", false); }

TEST(BinaryPackTests, Test11_FBKENNEDY_XLS) { TestHelpers::GetInst()->DecompressAndVerify("FB.KENNEDY.XLS", "PACK", false); }

TEST(BinaryPackTests, Test12_FBLCET10_TXT) { TestHelpers::GetInst()->DecompressAndVerify("FB.LCET10.TXT", "PACK", false); }

TEST(BinaryPackTests, Test13_FBPI_TXT) { TestHelpers::GetInst()->DecompressAndVerify("FB.PI.TXT", "PACK", false); }

TEST(BinaryPackTests, Test14_FBPLRABN12_TXT)
{
  TestHelpers::GetInst()->DecompressAndVerify("FB.PLRABN12.TXT", "PACK", false);
}

TEST(BinaryPackTests, Test15_FBPTT5) { TestHelpers::GetInst()->DecompressAndVerify("FB.PTT5", "PACK", false); }

TEST(BinaryPackTests, Test16_FBRANDOM_TXT) { TestHelpers::GetInst()->DecompressAndVerify("FB.RANDOM.TXT", "PACK", false); }

TEST(BinaryPackTests, Test17_FBSUM) { TestHelpers::GetInst()->DecompressAndVerify("FB.SUM", "PACK", false); }

TEST(BinaryPackTests, Test18_FB_WORLD192_TXT)
{
  TestHelpers::GetInst()->DecompressAndVerify("FB.WORLD192.TXT", "PACK", false);
}

TEST(BinaryPackTests, Test19_FBXARGS) { TestHelpers::GetInst()->DecompressAndVerify("FB.XARGS", "PACK", false); }

TEST(BinaryPackTests, Test20_VBBIBLE_TXT) { TestHelpers::GetInst()->DecompressAndVerify("VB.BIBLE.TXT", "PACK", false); }

TEST(BinaryPackTests, Test36_VBPLRABN12_TXT)
{
  TestHelpers::GetInst()->DecompressAndVerify("VB.PLRABN12.TXT", "PACK", false);
}
