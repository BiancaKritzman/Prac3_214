#ifndef MUSICZONE_H
#define MUSICZONE_H

#include "Zones.h"

struct Performance{
    std::string startTime;
    std::string endTime;
};

class MusicZone : public Zones {
    private:
        Performance schedule;
        bool isLive;
        std::string stageName;
    public:
        MusicZone(std::string stageName, bool isLive);
        void describe() override;
        std::string getSchedule() const;
        std::string getStageName() const;
        void setSchedule(std::string startTime, std::string endTime);
       
};


#endif