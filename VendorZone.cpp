#include "VendorZone.h"
#include <iostream>

VendorZone::VendorZone(std::string name, int stalls)
    : Zones(std::move(name)), totalStalls(stalls) {}

void VendorZone::describe() {
    std::cout << "VendorZone with " << totalStalls << " stalls\n";
}