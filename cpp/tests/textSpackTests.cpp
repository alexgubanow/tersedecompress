#include "../src/TerseDecompresser.h"
#include "testHelpers.h"

#include <gtest/gtest.h>

TEST(TextSPackTests, Test02_FBAAA_TXT) { TestHelpers::GetInst()->DecompressAndVerify("FB.AAA.TXT", "SPACK", true); }

TEST(TextSPackTests, Test04_FBALPHABET_TXT)
{
  TestHelpers::GetInst()->DecompressAndVerify("FB.ALPHABET.TXT", "SPACK", true);
}

TEST(TextSPackTests, Test06_FBBIBLE_TXT) { TestHelpers::GetInst()->DecompressAndVerify("FB.BIBLE.TXT", "SPACK", true); }

TEST(TextSPackTests, Test07_FBCP_HTML) { TestHelpers::GetInst()->DecompressAndVerify("FB.CP.HTML", "SPACK", true); }

TEST(TextSPackTests, Test08_FBE_COLI) { TestHelpers::GetInst()->DecompressAndVerify("FB.E.COLI", "SPACK", true); }

TEST(TextSPackTests, Test09_FBFIELDS_C) { TestHelpers::GetInst()->DecompressAndVerify("FB.FIELDS.C", "SPACK", true); }

TEST(TextSPackTests, Test10_FBGRAMMAR_LSP) { TestHelpers::GetInst()->DecompressAndVerify("FB.GRAMMAR.LSP", "SPACK", true); }

TEST(TextSPackTests, Test12_FBLCET10_TXT) { TestHelpers::GetInst()->DecompressAndVerify("FB.LCET10.TXT", "SPACK", true); }

TEST(TextSPackTests, Test13_FBPI_TXT) { TestHelpers::GetInst()->DecompressAndVerify("FB.PI.TXT", "SPACK", true); }

TEST(TextSPackTests, Test16_FBRANDOM_TXT) { TestHelpers::GetInst()->DecompressAndVerify("FB.RANDOM.TXT", "SPACK", true); }

TEST(TextSPackTests, Test18_FB_WORLD192_TXT)
{
  TestHelpers::GetInst()->DecompressAndVerify("FB.WORLD192.TXT", "SPACK", true);
}

TEST(TextSPackTests, Test19_FBXARGS) { TestHelpers::GetInst()->DecompressAndVerify("FB.XARGS", "SPACK", true); }

TEST(TextSPackTests, Test20_VBBIBLE_TXT) { TestHelpers::GetInst()->DecompressAndVerify("VB.BIBLE.TXT", "SPACK", true); }

TEST(TextSPackTests, Test21_VBCP_HTML) { TestHelpers::GetInst()->DecompressAndVerify("VB.CP.HTML", "SPACK", true); }

TEST(TextSPackTests, Test23_VBFIELDS_C) { TestHelpers::GetInst()->DecompressAndVerify("VB.FIELDS.C", "SPACK", true); }

TEST(TextSPackTests, Test24_VBGRAMMAR_LSP) { TestHelpers::GetInst()->DecompressAndVerify("VB.GRAMMAR.LSP", "SPACK", true); }

TEST(TextSPackTests, Test25_VBLCET10_TXT) { TestHelpers::GetInst()->DecompressAndVerify("VB.LCET10.TXT", "SPACK", true); }

TEST(TextSPackTests, Test26_VB_WORLD192_TXT)
{
  TestHelpers::GetInst()->DecompressAndVerify("VB.WORLD192.TXT", "SPACK", true);
}

TEST(TextSPackTests, Test27_VBXARGS) { TestHelpers::GetInst()->DecompressAndVerify("VB.XARGS", "SPACK", true); }

TEST(TextSPackTests, Test29_VBAAA_TXT) { TestHelpers::GetInst()->DecompressAndVerify("VB.AAA.TXT", "SPACK", true); }

TEST(TextSPackTests, Test30_VBALPHABET_TXT)
{
  TestHelpers::GetInst()->DecompressAndVerify("VB.ALPHABET.TXT", "SPACK", true);
}

TEST(TextSPackTests, Test31_VBE_COLI) { TestHelpers::GetInst()->DecompressAndVerify("VB.E.COLI", "SPACK", true); }

TEST(TextSPackTests, Test32_VBPI_TXT) { TestHelpers::GetInst()->DecompressAndVerify("VB.PI.TXT", "SPACK", true); }

TEST(TextSPackTests, Test33_VBRANDOM_TXT) { TestHelpers::GetInst()->DecompressAndVerify("VB.RANDOM.TXT", "SPACK", true); }

// The following test fails, but the file also uncompresses incorrectly using AMATERSE on z/OS.
// The failure seems to be in the SPACK compression using AMATERSE.
// TEST(TextSPackTests, Test01_FBA_TXT) { TestHelpers::GetInst()->DecompressAndVerify("FB.A.TXT", "SPACK", true); }
// TEST(TextSPackTests, Test28_VBA_TXT) { TestHelpers::GetInst()->DecompressAndVerify("VB.A.TXT", "SPACK", true); }