#ifndef SECURITY_H
#define SECURTIY_H

#include "MusicFestivalObserver.h"
#include "Notice.h"
#include <string>

class Zones;

//leaf
class Security: public MusicFestivalObserver {
    private:
        int gaurdCount;
        std::string currentZone;
        Zones* eventRoot;

    public:
        Security(int guards, std::string zone, Zones* root);
        void update(const Notice& notice) override;
        void dispatchToZone(std::string zoneName);
        void add(MusicFestivalObserver* child) override;
        void remove(MusicFestivalObserver* child) override;
        void describe() override;
};

#endif