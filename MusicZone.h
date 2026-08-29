#ifndef MUSICZONE_H
#define MUSICZONE_H

#include "Zones.h"

class MusicZone : public Zones {
    private:
        std::string stageName;
    public:
        void describe() override;
};

#endif