#ifndef STAGE_H
#define STAGE_H

#include "MusicFestivalObserver.h"

//leaf
class Stage: public MusicFestivalObserver {
    private:
        std::string currentArtist;
    public:
        Stage(std::string artist);
        virtual void open() = 0;
        virtual void close() = 0;
        void describe() override;
};

#endif