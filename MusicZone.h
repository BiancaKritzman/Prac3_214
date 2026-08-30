#ifndef MUSICZONE_H
#define MUSICZONE_H

#include "Zones.h"

class MusicZone : public Zones {
    public:
        std::string stageName;
        MusicZone(std::string name);
        void describe() override;
};

#endif