#include "lib/BrotherPrinter.hpp"
#include "lib/LexmarkPrinter.hpp"
#include "lib/PdfPrinter.hpp"
#include "lib/PrintersProxy.hpp"
#include <gtest/gtest.h>

class PrintersProxyFixture : public ::testing::Test {
public:
  PrintersProxy unit;
};

TEST_F(PrintersProxyFixture, ShouldAddPrinter) {
  unit.AddPrinter(std::make_unique<PdfPrinter>());
  ASSERT_EQ(unit.GetNumOfPrinters(), 1);
}

TEST_F(PrintersProxyFixture, ShouldRemovePrinter) {
  unit.AddPrinter(std::make_unique<PdfPrinter>());
  unit.RemovePrinter(0);
  ASSERT_EQ(unit.GetNumOfPrinters(), 0);
}

TEST_F(PrintersProxyFixture,
       ShouldThrowExceptionWhenRemovingPrinterWithinEmptyVector) {
  ASSERT_THROW(unit.RemovePrinter(2), std::exception);
}

TEST_F(PrintersProxyFixture,
       ShouldThrowExceptionWhenRemovingPrinterWithWrongIndex) {
  unit.AddPrinter(std::make_unique<PdfPrinter>());
  ASSERT_THROW(unit.RemovePrinter(2), std::exception);
}

TEST_F(PrintersProxyFixture, ShouldSetDefaultPrinter) {
  unit.AddPrinter(std::make_unique<PdfPrinter>());
  unit.AddPrinter(std::make_unique<PdfPrinter>());
  unit.SetDefaultPrinter(1);
  ASSERT_EQ(unit.GetIdxOfDefaultPrinter(), 1);
  ASSERT_EQ(unit.GetPrinterName(unit.GetIdxOfDefaultPrinter()), "PdfPrinter");
}

TEST_F(PrintersProxyFixture,
       ShouldThrowWhenAssigningDefaultPrinterWithoutPrinters) {
  ASSERT_THROW(unit.SetDefaultPrinter(0), std::exception);
  ASSERT_THROW(unit.SetDefaultPrinter(unit.GetIdxOfDefaultPrinter()),
               std::exception);
  ASSERT_THROW(unit.SetDefaultPrinter(2), std::exception);
}

TEST_F(PrintersProxyFixture, ShouldThrowWhenAssigningDefaultWithWrongIndex) {
  unit.AddPrinter(std::make_unique<PdfPrinter>());
  ASSERT_THROW(unit.SetDefaultPrinter(2), std::exception);
}

TEST_F(PrintersProxyFixture, ShouldThrowWhenPrintingWithoutPrinters) {
  ASSERT_THROW(unit.Print("TEXT"), std::exception);
  ASSERT_THROW(unit.Print("TEXT", 1), std::exception);
}

TEST_F(PrintersProxyFixture, ShouldThrowWhenPrintingWithWrongIndex) {
  unit.AddPrinter(std::make_unique<PdfPrinter>());
  ASSERT_THROW(unit.Print("TEXT", 1), std::exception);
}

TEST_F(PrintersProxyFixture, ShouldThrowWhenGettingNameOfWrongIndex) {
  unit.AddPrinter(std::make_unique<PdfPrinter>());
  ASSERT_THROW(unit.GetPrinterName(1), std::exception);
}

TEST_F(PrintersProxyFixture, ShouldThrowWhenGettingNameWithNoPrinters) {
  ASSERT_THROW(unit.GetPrinterName(0), std::exception);
}

TEST_F(PrintersProxyFixture, ShouldReturnRightNumberOfPrintersAdded) {
  unit.AddPrinter(std::make_unique<PdfPrinter>());
  unit.AddPrinter(std::make_unique<PdfPrinter>());
  unit.AddPrinter(std::make_unique<PdfPrinter>());
  ASSERT_EQ(unit.GetNumOfPrinters(), 3);
}

TEST_F(PrintersProxyFixture, ShouldReturnNumOfDefaultPrinter) {
  unit.AddPrinter(std::make_unique<PdfPrinter>());
  unit.SetDefaultPrinter(0);
  ASSERT_EQ(unit.GetIdxOfDefaultPrinter(), 0);
}

TEST_F(PrintersProxyFixture, ShouldReturnRightPrinterName) {
  unit.AddPrinter(std::make_unique<PdfPrinter>());
  ASSERT_EQ(unit.GetPrinterName(0), "PdfPrinter");
}

TEST_F(PrintersProxyFixture, ShouldShowZeroAsDefaultPrinter) {
  unit.AddPrinter(std::make_unique<PdfPrinter>());
  unit.AddPrinter(std::make_unique<PdfPrinter>());
  unit.AddPrinter(std::make_unique<PdfPrinter>());
  ASSERT_EQ(unit.GetIdxOfDefaultPrinter(), 0);
}

// TEST_F(PrintersProxyFixture, ) {
//  unit.AddPrinter(std::make_unique<PdfPrinter>());
// }