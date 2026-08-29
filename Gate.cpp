#include "Gate.h"
#include <iostream>

void Gate::open() {
    std::cout << "Stand back!! The stage gate is opening.\n";
}

void Gate::close() {
    std::cout << "Capacity limits have been reached. Stage gate is closing.\n";
}