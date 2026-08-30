#ifndef ZONES_H
#define ZONES_H

#include "MusicFestivalObserver.h"
#include <vector>
#include <string>

//composite
class Zones: public MusicFestivalObserver {
    private:
        std::string zoneName;
        std::vector<MusicFestivalObserver*> children;      // owned
        std::vector<MusicFestivalObserver*> observerList;  // non-owning

    public:
        Zones(std::string name);
        ~Zones() override;

        void add(MusicFestivalObserver* child) override;
        void remove(MusicFestivalObserver* child) override;

        void attach(MusicFestivalObserver* observer);
        void detach(MusicFestivalObserver* observer);
        void notify(const Notice& notice);

        void update(const Notice& notice) override;
        void describe() override;
};

#endif