#include "LexmarkPrinter.hpp"

void LexmarkPrinter::Print(const std::string &text_to_print) const {
  std::cout << "Printing on Lexmark..." << std::endl
            << text_to_print << std::endl;
}

std::string LexmarkPrinter::GetPrinterName() const { return "LexmarkPrinter"; }