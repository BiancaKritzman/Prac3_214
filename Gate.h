#ifndef GATE_H
#define GATE_H

#include "Stage.h"

class Gate: public Stage {
    public:
        void open() override;
        void close() override;
};

#endif