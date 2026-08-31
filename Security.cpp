#include "Security.h"
#include "Zones.h"
#include <iostream>

Security::Security(int guards, std::string zone, Zones* root)
    : gaurdCount(guards), currentZone(zone), eventRoot(root) {}

void Security::dispatchToZone(std::string zoneName) {
    currentZone = zoneName;
    Notice notice{"CAPACITY_ALERT", zoneName, "Capacity threshold reached", 0, 0};
    eventRoot->notify(notice);
}

void Security::update(const Notice& notice) {
    if (notice.type == "REPORT_THEFT") {
        currentZone = notice.zoneID;
        std::cout << gaurdCount << " guards dispatched to " << currentZone
                   << " following a theft report: " << notice.detail << "\n";
    }
}

void Security::add(MusicFestivalObserver* child) {
    std::cout << "Security is a leaf; add() has no effect.\n";
}

void Security::remove(MusicFestivalObserver* child) {
    std::cout << "Security is a leaf; remove() has no effect.\n";
}

void Security::describe() {
    std::cout << gaurdCount << " guards, currently at " << currentZone << "\n";
}