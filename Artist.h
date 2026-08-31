#ifndef ARTIST_H
#define ARTIST_H

#include "MusicZone.h"

class Artist : public MusicZone {
    private:
        std::string genre;
        std::string artistName; 

    public:
        Artist(std::string zoneName, bool isLive, std::string artistName, std::string genre);

        std::string getFinishTime();
        std::string getStartTime();

        void describe() override;
};

#endif