#ifndef REFRESHMENTS_H
#define REFRESHMENTS_H

#include "VendorZone.h"

class Refreshments: public VendorZone {
    private:
        std::string vendorName;
        int refreshmentCount;
        std::string stolenItem;
    public:
        void reportTheft();
};

#endif