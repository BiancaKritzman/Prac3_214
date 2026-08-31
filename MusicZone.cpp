#include "MusicZone.h"

MusicZone::MusicZone(std::string stageName, bool isLive) : Zones(std::move(stageName)), isLive(isLive){}


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