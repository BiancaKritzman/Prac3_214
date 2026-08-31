#include "Gate.h"
#include <iostream>

Gate::Gate(std::string artist) : Stage(std::move(artist)) {}

void Gate::open() {
    std::cout << "Stand back!! The stage gate is opening.\n";
}

void Gate::close() {
    std::cout << "Capacity limits have been reached. Stage gate is closing.\n";
}

void Gate::update(const Notice& notice) {
    if (notice.type == "CAPACITY_ALERT") {
        if (notice.currentCapacity >= notice.threshold) {
            close();
        } else {
            open();
        }
    } else if (notice.type == "OPEN") {
        open();
    } else if (notice.type == "CLOSE") {
        close();
    } else if (notice.type == "WEATHER_ALERT" || notice.type == "EVACUATE") {
        close();   //stop addmitting attendees
    }
}