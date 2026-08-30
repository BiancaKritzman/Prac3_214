#include "SoundTeam.h"
#include <iostream>

SoundTeam::SoundTeam() : currentMessage(""), announcement(nullptr) {}

void SoundTeam::update(const Notice& notice) {
    if (notice.type == "SCHEDULE_CHANGE") {
        makeAnnouncement("Schedule update: " + notice.detail);
    } else if (notice.type == "WEATHER_ALERT") {
        makeAnnouncement("Weather alert: please seek shelter in the covered areas.");
    } else if (notice.type == "EVACUATE") {
        makeAnnouncement("Evacuate now — please proceed calmly to the nearest exit.");
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