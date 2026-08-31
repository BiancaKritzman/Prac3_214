#ifndef GATE_H
#define GATE_H

#include "MusicFestivalObserver.h"


class Gate: public MusicFestivalObserver {
    private:
        std::string gateID;
        bool isOpen;
    public:
        Gate(bool open, std::string id);
        void describe() override;
        void update(const Notice& notice) override;
        void add(MusicFestivalObserver* child) override;
        void remove(MusicFestivalObserver* child) override;
        void setAndCall(bool open);
};

#endif

