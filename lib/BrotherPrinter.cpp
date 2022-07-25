#include "BrotherPrinter.hpp"

void BrotherPrinter::Print(const std::string &text_to_print) const {
  std::cout << "Printing on Brother..." << std::endl
            << text_to_print << std::endl;
}

std::string BrotherPrinter::GetPrinterName() const { return "BrotherPrinter"; }