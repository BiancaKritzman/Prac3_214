#ifndef MERCH_H
#define MERCH_H

#include "MusicFestivalObserver.h"
#include "VendorZone.h"
//#include "Notice.h"
#include <string>

//leaf
class Merch: public VendorZone {
    private:
        std::string artistName;

    public:
        Merch(std::string zoneName, int stalls, std::string artist);
        void requestAnnouncement();
        void update(const Notice& notice) override;
        void add(MusicFestivalObserver* child) override;
        void remove(MusicFestivalObserver* child) override;
        void describe() override;
};

#endif