#ifndef MUSICFESITVALOBSERVER_H
#define MUSICFESTIVALOBSERVER_H


#include <iostream>
#include <string>

//Component 
class MusicFestivalObserver {
    public:
        virtual ~MusicFestivalObserver() = default;
        virtual void add(MusicFestivalObserver* child) = 0;
        virtual void remove(MusicFestivalObserver* child) = 0;
        virtual void describe() = 0;
};

struct Notice {
    std::string type;       // e.g. "Theft"
    std::string zoneID; 
    std::string detail;     // e.g. The artist's name or the stolen item
};

#endif