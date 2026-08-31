#ifndef SOUNDTEAM_H
#define SOUNDTEAM_H

// SoundTeam.h
#include "MusicFestivalObserver.h"
//#include "Notice.h"
#include <string>

class Merch;

//leaf
class SoundTeam: public MusicFestivalObserver {
    private:
        std::string currentMessage;
        Merch* announcement;

    public:
        SoundTeam();
        void update(const Notice& notice) override;
        void makeAnnouncement(std::string msg);
        void add(MusicFestivalObserver* child) override;
        void remove(MusicFestivalObserver* child) override;
        void describe() override;
};

#endif