#include "Printer.hpp"
#include <iostream>

class PdfPrinter : public Printer {
public:
  void Print(const std::string &text_to_print) const override;
  std::string GetPrinterName() const override;
};