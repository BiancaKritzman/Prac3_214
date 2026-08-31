#include "Gate.h"
#include <iostream>

Gate::Gate(bool open) : isOpen(open) {}

void Gate::describe() {
    if (isOpen) {
        std::cout << "Stand back!! The stage gate is opening.\n";
    }
    else {
        std::cout << "Capacity limits have been reached. Stage gate is closing.\n";
    }
}

void Gate::setAndCall(bool open) {
    isOpen = open;
    describe();
}

void Gate::update(const Notice& notice) {
    if (notice.type == "CAPACITY_ALERT") {
        if (notice.currentCapacity >= notice.threshold) {
            setAndCall(false);
        } else {
            setAndCall(true);
        }
    } else if (notice.type == "OPEN") {
        setAndCall(true);
    } else if (notice.type == "CLOSE") {
        setAndCall(false);
    } else if (notice.type == "THEFT_ALERT") {
        setAndCall(false);   //stop addmitting attendees
    }
}