#include "MusicZone.h"


MusicZone::MusicZone(std::string name) : Zones(std::move(name)) {}
void MusicZone::describe() { std::cout << "MusicZone\n"; }

void MusicZone::describe(){
    std::cout << "Stage: " << stageName << "\n";
}