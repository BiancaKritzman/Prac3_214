#include "MusicFestivalObserver.h"
#include <vector>
#include <string>

//leaf
class Zones: public MusicFestivalObserver {
    private:
        std::string zoneName;
        std::vector<MusicFestivalObserver*> children;
    public:
        Zones(std::string name);
        ~Zones() override;
        void add(MusicFestivalObserver* child) override;
        void remove(MusicFestivalObserver* child) override;
        void describe() override;

};