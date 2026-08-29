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

#endif