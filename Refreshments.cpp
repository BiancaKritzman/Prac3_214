#include "Refreshments.h"

Refreshments::Refreshments(std::string zoneName, int stalls, std::string vendorName, int initialCount)
    : VendorZone(std::move(zoneName), stalls), 
      vendorName(std::move(vendorName)), 
      refreshmentCount(initialCount), 
      stolenItem("") {}

void Refreshments::describe() {
    std::cout << refreshmentCount << " refreshments are sold by " << vendorName << "\n";
}

void Refreshments::reportTheft(std::string item) {
    stolenItem = item;
    std::cout << "Theft reported at " << vendorName << "'s stall! Stolen item: " << item << "\n";
    Notice notice{"REPORT_THEFT", "Vendor Zone", item, 0, 0};
    parentZone->notify(notice);
}