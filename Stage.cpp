#include "Stage.h"
#include <iostream>

Stage::Stage(std::string artist) : currentArtist(std::move(artist)) {}

void Stage::add(MusicFestivalObserver* child) {
    std::cout << "Stage is a leaf; add() has no effect.\n";
}

void Stage::remove(MusicFestivalObserver* child) {
    std::cout << "Stage is a leaf; remove() has no effect.\n";
}

void Stage::describe() {
    std::cout << currentArtist << " is lighting up the stage!\n";
}

void Stage::update(const Notice& notice) {
    if (notice.type == "REPORT_THEFT") {
        std::cout << "Security alert: Theft reported at the stage!\n";
    } else if (notice.type == "ANNOUNCE_MERCH") {
        std::cout << "Merchandise alert: Check for stolen items at the stage!\n";
    }
}