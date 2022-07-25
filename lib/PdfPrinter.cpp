#include "PdfPrinter.hpp"

void PdfPrinter::Print(const std::string &text_to_print) const {
  std::cout << "Printing to PDF..." << std::endl << text_to_print << std::endl;
}

std::string PdfPrinter::GetPrinterName() const { return "PdfPrinter"; }