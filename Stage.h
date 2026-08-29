#include "MusicFestival.h"

//leaf
class Stage: public MusicFestival {
    public:
        virtual void open() = 0;
        virtual void close() = 0;
};