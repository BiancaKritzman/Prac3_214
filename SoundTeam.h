#ifndef SOUNDTEAM_H
#define SOUNDTEAM_H

#include "MusicFestivalObserver.h"

//leaf
class SoundTeam: public MusicFestivalObserver {
    public:
        void describe() override;
};

#endif