#ifndef MUSICZONE_H
#define MUSICZONE_H

#include "Zones.h"

class MusicZone : public Zones {
    private:
        bool isLive;
    public:
        MusicZone(std::string name, bool isLive);
        void describe() override;
};

#endif