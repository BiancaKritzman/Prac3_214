#ifndef VENDORZONE_H
#define VENDORZONE_H

#include "Zones.h"

class VendorZone : public Zones {
    private:
        int totalStalls;
    public:
        void describe() override;
};

#endif