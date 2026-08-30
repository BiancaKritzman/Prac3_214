#include "Zones.h"
#include <algorithm>
#include <iostream>

Zones::Zones(std::string name) : zoneName(name) {}

Zones::~Zones() {
    for (MusicFestivalObserver* child : children) {
        delete child;
    }
}

void Zones::add(MusicFestivalObserver* child) {
    children.push_back(child);
}

void Zones::remove(MusicFestivalObserver* child) {
    // Ownership is released - not destroyed
    children.erase(std::remove(children.begin(), children.end(), child), children.end());
}

void Zones::attach(MusicFestivalObserver* observer) {
    if (std::find(observerList.begin(), observerList.end(), observer) == observerList.end()) {
        observerList.push_back(observer);
    }
}

void Zones::detach(MusicFestivalObserver* observer) {
    observerList.erase(std::remove(observerList.begin(), observerList.end(), observer), observerList.end());
}

void Zones::notify(const Notice& notice) {
    for (MusicFestivalObserver* observer : observerList) {
        observer->update(notice);
    }
}

void Zones::update(const Notice& notice) {
    notify(notice);
}

void Zones::describe() {
    std::cout << "Zone: " << zoneName << "\n";
}