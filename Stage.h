#include "MusicFestivalObserver.h"
#include <string>

//leaf
class Stage: public MusicFestivalObserver {
    private:
        std::string currentArtist;
    public:
        virtual void open() = 0;
        virtual void close() = 0;
        void describe() override;
};