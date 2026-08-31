#ifndef STAGE_H
#define STAGE_H

#include "MusicFestivalObserver.h"
#include "Notice.h"
#include <string>

//leaf
class Stage: public MusicFestivalObserver {
    private:
        std::string currentArtist;
    public:
        Stage(std::string artist);
        void add(MusicFestivalObserver* child) override;
        void remove(MusicFestivalObserver* child) override;
        void describe() override;
};

#endif