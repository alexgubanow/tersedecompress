#include "../src/TerseDecompresser.h"
#include "testHelpers.h"

#include <gtest/gtest.h>

TEST(BinarySPackTests, Test02_FBAAA_TXT) { TestHelpers::GetInst()->DecompressAndVerify("FB.AAA.TXT", "SPACK", false); }

TEST(BinarySPackTests, Test03_FBALICE29_TXT)
{
  TestHelpers::GetInst()->DecompressAndVerify("FB.ALICE29.TXT", "SPACK", false);
}

TEST(BinarySPackTests, Test04_FBALPHABET_TXT)
{
  TestHelpers::GetInst()->DecompressAndVerify("FB.ALPHABET.TXT", "SPACK", false);
}

TEST(BinarySPackTests, Test05_FBASYOU_LIK_TXT)
{
  TestHelpers::GetInst()->DecompressAndVerify("FB.ASYOULIK.TXT", "SPACK", false);
}

TEST(BinarySPackTests, Test06_FBBIBLE_TXT) { TestHelpers::GetInst()->DecompressAndVerify("FB.BIBLE.TXT", "SPACK", false); }

TEST(BinarySPackTests, Test07_FBCP_HTML) { TestHelpers::GetInst()->DecompressAndVerify("FB.CP.HTML", "SPACK", false); }

TEST(BinarySPackTests, Test08_FBE_COLI) { TestHelpers::GetInst()->DecompressAndVerify("FB.E.COLI", "SPACK", false); }

TEST(BinarySPackTests, Test09_FBFIELDS_C) { TestHelpers::GetInst()->DecompressAndVerify("FB.FIELDS.C", "SPACK", false); }

TEST(BinarySPackTests, Test10_FBGRAMMAR_LSP)
{
  TestHelpers::GetInst()->DecompressAndVerify("FB.GRAMMAR.LSP", "SPACK", false);
}

TEST(BinarySPackTests, Test11_FBKENNEDY_XLS)
{
  TestHelpers::GetInst()->DecompressAndVerify("FB.KENNEDY.XLS", "SPACK", false);
}

TEST(BinarySPackTests, Test12_FBLCET10_TXT) { TestHelpers::GetInst()->DecompressAndVerify("FB.LCET10.TXT", "SPACK", false); }

TEST(BinarySPackTests, Test13_FBPI_TXT) { TestHelpers::GetInst()->DecompressAndVerify("FB.PI.TXT", "SPACK", false); }

TEST(BinarySPackTests, Test14_FBPLRABN12_TXT)
{
  TestHelpers::GetInst()->DecompressAndVerify("FB.PLRABN12.TXT", "SPACK", false);
}

TEST(BinarySPackTests, Test15_FBPTT5) { TestHelpers::GetInst()->DecompressAndVerify("FB.PTT5", "SPACK", false); }

TEST(BinarySPackTests, Test16_FBRANDOM_TXT) { TestHelpers::GetInst()->DecompressAndVerify("FB.RANDOM.TXT", "SPACK", false); }

TEST(BinarySPackTests, Test17_FBSUM) { TestHelpers::GetInst()->DecompressAndVerify("FB.SUM", "SPACK", false); }

TEST(BinarySPackTests, Test18_FB_WORLD192_TXT)
{
  TestHelpers::GetInst()->DecompressAndVerify("FB.WORLD192.TXT", "SPACK", false);
}

TEST(BinarySPackTests, Test19_FBXARGS) { TestHelpers::GetInst()->DecompressAndVerify("FB.XARGS", "SPACK", false); }

TEST(BinarySPackTests, Test20_VBBIBLE_TXT) { TestHelpers::GetInst()->DecompressAndVerify("VB.BIBLE.TXT", "SPACK", false); }

TEST(BinarySPackTests, Test21_VBCP_HTML) { TestHelpers::GetInst()->DecompressAndVerify("VB.CP.HTML", "SPACK", false); }

TEST(BinarySPackTests, Test22_VBENWIK8_XML) { TestHelpers::GetInst()->DecompressAndVerify("VB.ENWIK8.XML", "SPACK", false); }

TEST(BinarySPackTests, Test23_VBFIELDS_C) { TestHelpers::GetInst()->DecompressAndVerify("VB.FIELDS.C", "SPACK", false); }

TEST(BinarySPackTests, Test24_VBGRAMMAR_LSP)
{
  TestHelpers::GetInst()->DecompressAndVerify("VB.GRAMMAR.LSP", "SPACK", false);
}

TEST(BinarySPackTests, Test25_VBLCET10_TXT) { TestHelpers::GetInst()->DecompressAndVerify("VB.LCET10.TXT", "SPACK", false); }

TEST(BinarySPackTests, Test26_VB_WORLD192_TXT)
{
  TestHelpers::GetInst()->DecompressAndVerify("VB.WORLD192.TXT", "SPACK", false);
}

TEST(BinarySPackTests, Test27_VBXARGS) { TestHelpers::GetInst()->DecompressAndVerify("VB.XARGS", "SPACK", false); }

TEST(BinarySPackTests, Test29_VBAAA_TXT) { TestHelpers::GetInst()->DecompressAndVerify("VB.AAA.TXT", "SPACK", false); }

TEST(BinarySPackTests, Test30_VBALPHABET_TXT)
{
  TestHelpers::GetInst()->DecompressAndVerify("VB.ALPHABET.TXT", "SPACK", false);
}

TEST(BinarySPackTests, Test31_VBE_COLI) { TestHelpers::GetInst()->DecompressAndVerify("VB.E.COLI", "SPACK", false); }

TEST(BinarySPackTests, Test32_VBPI_TXT) { TestHelpers::GetInst()->DecompressAndVerify("VB.PI.TXT", "SPACK", false); }

TEST(BinarySPackTests, Test33_VBRANDOM_TXT) { TestHelpers::GetInst()->DecompressAndVerify("VB.RANDOM.TXT", "SPACK", false); }

TEST(BinarySPackTests, Test34_VBALICE29_TXT)
{
  TestHelpers::GetInst()->DecompressAndVerify("VB.ALICE29.TXT", "SPACK", false);
}

TEST(BinarySPackTests, Test35_VBASYOU_LIK_TXT)
{
  TestHelpers::GetInst()->DecompressAndVerify("VB.ASYOULIK.TXT", "SPACK", false);
}

TEST(BinarySPackTests, Test36_VBPLRABN12_TXT)
{
  TestHelpers::GetInst()->DecompressAndVerify("VB.PLRABN12.TXT", "SPACK", false);
}

// The following test fails, but the file also uncompresses incorrectly using AMATERSE on z/OS.
// The failure seems to be in the SPACK compression using AMATERSE.
// TEST(BinarySPackTests, Test01_FBA_TXT) { TestHelpers::GetInst()->DecompressAndVerify("FB.A.TXT", "SPACK", false); }
// TEST(BinarySPackTests, Test28_VBA_TXT) { TestHelpers::GetInst()->DecompressAndVerify("VB.A.TXT", "SPACK", false); }