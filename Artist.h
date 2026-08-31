#ifndef ARTIST_H
#define ARTIST_H

#include "MusicZone.h"

class Artist: public MusicZone {
    private:
        std::string genre;
        std::string name;
    public:
        std::string getFinishTime();
        std::string getStartTime();
};

#endif