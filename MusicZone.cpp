#include "MusicZone.h"

MusicZone::MusicZone(std::string name, bool isLive) : Zones(std::move(name)), isLive(isLive){}


void MusicZone::describe(){
    if (isLive) {
        std::cout << "Stage is live.\n";
    }
    else {
        std::cout << "Stage will be live soon.\n";
    }
}