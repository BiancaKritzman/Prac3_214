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