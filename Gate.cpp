#include "Gate.h"
#include <iostream>

Gate::Gate(bool open) : isOpen(open) {}

void Gate::describe() {
    if (isOpen) {
        std::cout << "Stand back!! The stage gate " << gateID << "is opening.\n";
    }
    else {
        std::cout << "Capacity limits have been reached. Stage gate" << gateID <<" is closing.\n";
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
    } else if (notice.type == "GATE_OPEN") {
        setAndCall(true);
    } else if (notice.type == "GATE_CLOSE") {
        setAndCall(false);
    }
}

void Gate::add(MusicFestivalObserver* child) {
    std::cout << "Gate is a leaf; add() has no effect.\n";
}

void Gate::remove(MusicFestivalObserver* child) {
    std::cout << "Gate is a leaf; remove() has no effect.\n";
}