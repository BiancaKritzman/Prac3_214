#ifndef CROWD_H
#define CROWD_H

#include "MusicZone.h"

class Crowd: public MusicZone {
    private:
        int maxCapacity;
        int currentCapacity;
    public:
        void setCapacity(int capacity);
        int getCapacity();
};

#endif