#include "SoundTeam.h"
#include <iostream>

SoundTeam::SoundTeam() : currentMessage(""), announcement(nullptr) {}

void SoundTeam::update(const Notice& notice) {
    if (notice.type == "BROADCAST_SCHEDULE") {
        makeAnnouncement("Schedule update: " + notice.detail);
    } else if (notice.type == "ANNOUNCE_MERCH") {
        makeAnnouncement("New merch now available for " + notice.detail + " — head to the vendor zone!");
    }
}

void SoundTeam::makeAnnouncement(std::string msg) {
    currentMessage = msg;
    std::cout << "[Announcement] " << currentMessage << "\n";
}

void SoundTeam::add(MusicFestivalObserver* child) {
    std::cout << "SoundTeam is a leaf; add() has no effect.\n";
}

void SoundTeam::remove(MusicFestivalObserver* child) {
    std::cout << "SoundTeam is a leaf; remove() has no effect.\n";
}

void SoundTeam::describe() {
    std::cout << "SoundTeam - last announcement: " << currentMessage << "\n";
}