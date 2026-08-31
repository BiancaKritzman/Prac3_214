#ifndef CROWD_H
#define CROWD_H

#include "MusicZone.h"

class Crowd : public MusicZone {
    private:
        int maxCapacity;
        int currentCapacity;
    public:
        Crowd(std::string name, bool isLive, int maxCap);

        void setCapacity(int capacity);
        int getCapacity();
        void describe() override;
};

#endif