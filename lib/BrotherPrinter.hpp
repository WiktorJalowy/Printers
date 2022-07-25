#include "Printer.hpp"
#include <iostream>

class BrotherPrinter : public Printer {
public:
  void Print(const std::string &text_to_print) const override;
  std::string virtual GetPrinterName() const override;
};