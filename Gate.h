#ifndef GATE_H
#define GATE_H

#include "MusicFestivalObserver.h"
#include "Notice.h"

class Gate: public MusicFestivalObserver {
    private:
        bool isOpen;
    public:
        Gate(bool open);
        void describe() override;
        // void open();
        // void close();
        void update(const Notice& notice) override;
        void setAndCall(bool open);
};

#endif