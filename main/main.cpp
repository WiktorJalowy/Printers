#include "lib/BrotherPrinter.hpp"
#include "lib/LexmarkPrinter.hpp"
#include "lib/PdfPrinter.hpp"
#include "lib/PrintersProxy.hpp"
#include <iostream>

int main(int argc, char **argv) {
  PrintersProxy printers;
  printers.AddPrinter(std::make_unique<PdfPrinter>());
  printers.AddPrinter(std::make_unique<BrotherPrinter>());
  printers.AddPrinter(std::make_unique<LexmarkPrinter>());
  printers.SetDefaultPrinter(1);
  printers.Print("some text", 2);
  printers.Print("some text");
  printers.RemovePrinter(5);
  return 0;
}
