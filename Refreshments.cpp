#include "Refreshments.h"

Refreshments::Refreshments(std::string zoneName, int stalls, std::string vendorName, int initialCount)
    : VendorZone(std::move(zoneName), stalls), 
      vendorName(std::move(vendorName)), 
      refreshmentCount(initialCount), 
      stolenItem("") {}

void Refreshments::describe() {
    std::cout << refreshmentCount << " refreshments are sold by " << vendorName << "\n";
}

void Refreshments::reportTheft() { //idk?
    std::cout << "Theft reported at " << vendorName << "'s stall!\n";
}