#include "Zones.h"

Zones::Zones(std::string name) : zoneName(name) {};

Zones::~Zones() {
    for (MusicFestivalObserver* child : children) {
        delete child;
    }
}

void Zones::add(MusicFestivalObserver* child) {
    children.push_back(child);
}

void Zones::remove(MusicFestivalObserver* child) {
    for (size_t i = 0; i < children.size(); ++i) {
        if (children[i] == child) {
            delete children[i];                 
            children.erase(children.begin() + i); 
            break;                              
        }
    }
}

void Zones::describe(){
    std::cout << "Zone: " << zoneName << "\n";
}