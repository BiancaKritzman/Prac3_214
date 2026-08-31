#ifndef GATE_H
#define GATE_H

#include "MusicFestivalObserver.h"
struct Notice {
    std::string type;
    std::string zoneID;
    std::string detail;
    int currentCapacity = 0;
    int threshold = 0;
};

class Gate: public MusicFestivalObserver {
    private:
        std::string gateID;
        bool isOpen;
    public:
        Gate(bool open);
        void describe() override;
        void update(const Notice& notice) override;
        void add(MusicFestivalObserver* child) override;
        void remove(MusicFestivalObserver* child) override;
        void setAndCall(bool open);
};

#endif