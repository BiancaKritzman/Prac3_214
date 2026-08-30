#ifndef MERCH_H
#define MERCH_H

#include "VendorZone.h"

class Merch: public VendorZone {
    private:
        std::string artistName;
    public:
        void requestAnnouncement();
};

#endif