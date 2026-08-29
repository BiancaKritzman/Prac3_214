#ifndef SECURITY_H
#define SECURITY_H

#include "MusicFestivalObserver.h"

//leaf
class Security: public MusicFestivalObserver {
    private:
        int guardCount;
        std::string currentZone;
    public:
        void describe() override;
};

#endif