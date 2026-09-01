#include "Crowd.h"

Crowd::Crowd(std::string name, bool isLive, int maxCap) 
    : MusicZone(std::move(name), isLive), maxCapacity(maxCap), currentCapacity(0) {}

void Crowd::setCapacity(int capacity) {
    maxCapacity = capacity;
}

int Crowd::getCapacity() {
    return maxCapacity;
}

void Crowd::describe() {
    if (currentCapacity > maxCapacity) {
        std::cout << "Crowd hazard! Capacity exceeded.\n";
    }
    else if ((maxCapacity - currentCapacity) < 20) { 
        std::cout << "Crowd capacity is close to full\n";
    }
    else {
        std::cout << "Crowd capacity is stable and can increase\n";
    }
}