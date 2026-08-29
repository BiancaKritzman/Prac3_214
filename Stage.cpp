#include "Stage.h"

Stage::Stage(std::string artist): currentArtist(artist) {}

void Stage::describe() {
    std::cout << currentArtist << "is lighting up the stage!\n";
}