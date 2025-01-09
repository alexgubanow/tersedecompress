#include "../src/TerseDecompresser.h"
#include "testHelpers.h"

#include <gtest/gtest.h>

TEST(TextPackTests, Test01_FBA_TXT) { TestHelpers::GetInst()->DecompressAndVerify("FB.A.TXT", "PACK", true); }

TEST(TextPackTests, Test02_FBAAA_TXT) { TestHelpers::GetInst()->DecompressAndVerify("FB.AAA.TXT", "PACK", true); }

TEST(TextPackTests, Test04_FBALPHABET_TXT) { TestHelpers::GetInst()->DecompressAndVerify("FB.ALPHABET.TXT", "PACK", true); }

TEST(TextPackTests, Test06_FBBIBLE_TXT) { TestHelpers::GetInst()->DecompressAndVerify("FB.BIBLE.TXT", "PACK", true); }

TEST(TextPackTests, Test07_FBCP_HTML) { TestHelpers::GetInst()->DecompressAndVerify("FB.CP.HTML", "PACK", true); }

TEST(TextPackTests, Test08_FBE_COLI) { TestHelpers::GetInst()->DecompressAndVerify("FB.E.COLI", "PACK", true); }

TEST(TextPackTests, Test09_FBFIELDS_C) { TestHelpers::GetInst()->DecompressAndVerify("FB.FIELDS.C", "PACK", true); }

TEST(TextPackTests, Test10_FBGRAMMAR_LSP) { TestHelpers::GetInst()->DecompressAndVerify("FB.GRAMMAR.LSP", "PACK", true); }

TEST(TextPackTests, Test12_FBLCET10_TXT) { TestHelpers::GetInst()->DecompressAndVerify("FB.LCET10.TXT", "PACK", true); }

TEST(TextPackTests, Test13_FBPI_TXT) { TestHelpers::GetInst()->DecompressAndVerify("FB.PI.TXT", "PACK", true); }

TEST(TextPackTests, Test16_FBRANDOM_TXT) { TestHelpers::GetInst()->DecompressAndVerify("FB.RANDOM.TXT", "PACK", true); }

TEST(TextPackTests, Test18_FB_WORLD192_TXT) { TestHelpers::GetInst()->DecompressAndVerify("FB.WORLD192.TXT", "PACK", true); }

TEST(TextPackTests, Test19_FBXARGS) { TestHelpers::GetInst()->DecompressAndVerify("FB.XARGS", "PACK", true); }

TEST(TextPackTests, Test20_VBBIBLE_TXT) { TestHelpers::GetInst()->DecompressAndVerify("VB.BIBLE.TXT", "PACK", true); }

TEST(TextPackTests, Test21_VBCP_HTML) { TestHelpers::GetInst()->DecompressAndVerify("VB.CP.HTML", "PACK", true); }

TEST(TextPackTests, Test23_VBFIELDS_C) { TestHelpers::GetInst()->DecompressAndVerify("VB.FIELDS.C", "PACK", true); }

TEST(TextPackTests, Test24_VBGRAMMAR_LSP) { TestHelpers::GetInst()->DecompressAndVerify("VB.GRAMMAR.LSP", "PACK", true); }

TEST(TextPackTests, Test25_VBLCET10_TXT) { TestHelpers::GetInst()->DecompressAndVerify("VB.LCET10.TXT", "PACK", true); }

TEST(TextPackTests, Test26_VB_WORLD192_TXT) { TestHelpers::GetInst()->DecompressAndVerify("VB.WORLD192.TXT", "PACK", true); }

TEST(TextPackTests, Test27_VBXARGS) { TestHelpers::GetInst()->DecompressAndVerify("VB.XARGS", "PACK", true); }

TEST(TextPackTests, Test28_VBA_TXT) { TestHelpers::GetInst()->DecompressAndVerify("VB.A.TXT", "PACK", true); }

TEST(TextPackTests, Test29_VBAAA_TXT) { TestHelpers::GetInst()->DecompressAndVerify("VB.AAA.TXT", "PACK", true); }

TEST(TextPackTests, Test30_VBALPHABET_TXT) { TestHelpers::GetInst()->DecompressAndVerify("VB.ALPHABET.TXT", "PACK", true); }

TEST(TextPackTests, Test31_VBE_COLI) { TestHelpers::GetInst()->DecompressAndVerify("VB.E.COLI", "PACK", true); }

TEST(TextPackTests, Test32_VBPI_TXT) { TestHelpers::GetInst()->DecompressAndVerify("VB.PI.TXT", "PACK", true); }

TEST(TextPackTests, Test33_VBRANDOM_TXT) { TestHelpers::GetInst()->DecompressAndVerify("VB.RANDOM.TXT", "PACK", true); }
