#pragma once
#include "Printer.hpp"
#include <exception>
#include <memory>
#include <vector>
#include <iostream>

class PrintersProxy {
public:
  void AddPrinter(std::unique_ptr<Printer> printer);
  void RemovePrinter(int printer_idx);
  void SetDefaultPrinter(long unsigned int printer_idx);
  void Print(std::string text_to_print);
  void Print(std::string text_to_print, int printer_idx);
  int GetNumOfPrinters();
  std::string GetPrinterName(int printer_idx);
  int GetIdxOfDefaultPrinter();

private:
  std::vector<std::unique_ptr<Printer>> allprinters;
  int defaultprinteridx = 0;
};