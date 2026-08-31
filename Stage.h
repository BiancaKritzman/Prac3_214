#include "MusicFestivalObserver.h"
#include "Notice.h"
#include <string>

//leaf
class Stage: public MusicFestivalObserver {
    private:
        std::string currentArtist;
    public:
        Stage(std::string artist);
        virtual void open() = 0;
        virtual void close() = 0;
        void add(MusicFestivalObserver* child) override;
        void remove(MusicFestivalObserver* child) override;
        void describe() override;
};