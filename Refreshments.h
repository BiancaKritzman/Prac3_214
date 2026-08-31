#ifndef REFRESHMENTS_H
#define REFRESHMENTS_H

#include "VendorZone.h"

class Refreshments: public VendorZone {
    private:
        std::string vendorName;
        int refreshmentCount;
        std::string stolenItem;
        VendorZone* parentZone;
    public:
        Refreshments(std::string zoneName, int stalls, std::string vendorName, int initialCount);
        void Refreshments::reportTheft(std::string item);
        void describe() override;
};

#endif