#ifndef MUSICFESTIVALOBSERVER_H
#define MUSICFESTIVALOBSERVER_H

#include <iostream>
#include <string>
//#include "Notice.h"
struct Notice {
    std::string type;       // e.g. "Theft"
    std::string zoneID; 
    std::string detail;     // e.g. The artist's name or the stolen item
    int currentCapacity;
    int threshold;

    Notice(std::string type, std::string zoneID, std::string detail,
           int currentCapacity = 0, int threshold = 0)
        : type(std::move(type)), zoneID(std::move(zoneID)), detail(std::move(detail)),
          currentCapacity(currentCapacity), threshold(threshold) {}
    
};
//Component 
class MusicFestivalObserver {
    public:
        virtual ~MusicFestivalObserver() = default;
        virtual void update(const Notice& notice) = 0;
        virtual void add(MusicFestivalObserver* child) = 0;
        virtual void remove(MusicFestivalObserver* child) = 0;
        virtual void describe() = 0;
};



#endif
