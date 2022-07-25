#pragma once
#include <string>

class Printer {
public:
  virtual void Print(const std::string &text_to_print) const = 0;
  virtual std::string GetPrinterName() const = 0;
};