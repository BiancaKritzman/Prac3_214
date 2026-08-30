#include "Merch.h"
#include <iostream>

Merch::Merch(std::string artist) : artistName(artist) {}

void Merch::requestAnnouncement() {
    std::cout << artistName << "'s merch is ready for sale.\n";
}

void Merch::update(const Notice& notice) {
    // merch doesnt react to any notice
}

void Merch::add(MusicFestivalObserver* child) {
    std::cout << "Merch is a leaf; add() has no effect.\n";
}

void Merch::remove(MusicFestivalObserver* child) {
    std::cout << "Merch is a leaf; remove() has no effect.\n";
}

void Merch::describe() {
    std::cout << "Merch stand - " << artistName << "\n";
}