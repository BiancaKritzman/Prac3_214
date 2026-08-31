#ifndef GATE_H
#define GATE_H

#include "MusicFestivalObserver.h"
#include "Notice.h"

class Gate: public MusicFestivalObserver {
    private:
        std::string gateID;
        bool isOpen;
    public:
        Gate(bool open);
        void describe() override;

        void update(const Notice& notice) override;
        void setAndCall(bool open); //our open() and close()
};

#endif