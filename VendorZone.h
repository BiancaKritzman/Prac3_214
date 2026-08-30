#ifndef VENDORZONE_H
#define VENDORZONE_H

#include "Zones.h"

class VendorZone : public Zones {
    private:
        int totalStalls;
    public:
        VendorZone(std::string name, int stalls);
        void describe() override;
};

#endif