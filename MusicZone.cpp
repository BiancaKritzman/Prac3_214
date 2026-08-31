#include "MusicZone.h"

   MusicZone::MusicZone(std::string name, bool isLive)
       : Zones(name), isLive(isLive), stageName(std::move(name)) {}

void MusicZone::describe(){
    if (isLive) {
        std::cout << "Stage is live.\n";
    }
    else {
        std::cout << "Stage will be live soon.\n";
    }
}

std::string MusicZone::getStageName() const {
    return stageName;
}
std::string MusicZone::getSchedule() const {
    return "Performance from " + schedule.startTime + " to " + schedule.endTime + " at " + stageName;
}

void MusicZone::setSchedule(std::string startTime, std::string endTime) {
    schedule.startTime = std::move(startTime);
    schedule.endTime = std::move(endTime);
}