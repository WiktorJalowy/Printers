#include "PrintersProxy.hpp"

void PrintersProxy::AddPrinter(std::unique_ptr<Printer> printer) {
  allprinters.push_back(std::move(printer));
}

void PrintersProxy::RemovePrinter(int printer_idx) {
  if (allprinters.size() != 0 && printer_idx >= 0 &&
      printer_idx <= allprinters.size() - 1) {
    allprinters.erase(allprinters.begin() + printer_idx);
  } else {
    throw std::out_of_range("Out of range");
  }
}

void PrintersProxy::SetDefaultPrinter(long unsigned int printer_idx) {
  if (allprinters.size() != 0 && printer_idx >= 0 &&
      printer_idx <= allprinters.size() - 1) {
    defaultprinteridx = printer_idx;
  } else {
    throw std::out_of_range("Out of range");
  }
}

void PrintersProxy::Print(std::string text_to_print) {
  if (allprinters.size() != 0) {
    allprinters[defaultprinteridx]->Print(text_to_print);
  } else {
    throw std::out_of_range("Out of range");
  }
}

void PrintersProxy::Print(std::string text_to_print, int printer_idx) {
  if (allprinters.size() != 0 && printer_idx >= 0 &&
      printer_idx <= allprinters.size() - 1) {
    allprinters[printer_idx]->Print(text_to_print);
  } else {
    throw std::out_of_range("Out of range");
  }
}

int PrintersProxy::GetNumOfPrinters() { return allprinters.size(); }

std::string PrintersProxy::GetPrinterName(int printer_idx) {
  if (allprinters.size() != 0 && printer_idx >= 0 &&
      printer_idx <= allprinters.size() - 1) {
    return allprinters[printer_idx]->GetPrinterName();
  } else {
    throw std::out_of_range("Out of range");
  }
}

int PrintersProxy::GetIdxOfDefaultPrinter() { return defaultprinteridx; }