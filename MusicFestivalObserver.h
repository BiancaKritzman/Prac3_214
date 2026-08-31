#ifndef MUSICFESITVALOBSERVER_H
#define MUSICFESTIVALOBSERVER_H


#include <iostream>
#include <string>
#include "Notice.h"

//Component 
class MusicFestivalObserver {
    public:
        virtual void update(const Notice& notice) = 0;
        virtual ~MusicFestivalObserver() = default;
        virtual void add(MusicFestivalObserver* child) = 0;
        virtual void remove(MusicFestivalObserver* child) = 0;
        virtual void describe() = 0;
};

struct Notice {
    std::string type;       // e.g. "Theft"
    std::string zoneID; 
    std::string detail;     // e.g. The artist's name or the stolen item
    int currentCapacity = 0;
    int threshold = 0;
    
};

#endif