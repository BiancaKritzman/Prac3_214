#ifndef MUSICZONE_H
#define MUSICZONE_H

#include "Zones.h"

/**
 * @brief Stores the start and end times of a performance.
 */
struct Performance{
    std::string startTime;
    std::string endTime;
};

/**
 * @brief Represents a music-focused festival zone.
 *
 * MusicZone extends Zones with performance scheduling and live-status
 * information. It remains a Composite because it inherits the ability
 * to contain child MusicFestivalObserver components.
 */
class MusicZone : public Zones {
    private:
        Performance schedule;
        bool isLive;
        std::string stageName;
    public:

        /**
         * @brief Constructs a music zone.
         *
         * @param stageName Name of the stage associated with the zone.
         * @param isLive True if the stage is currently live; false otherwise.
         */
        MusicZone(std::string stageName, bool isLive);

        /**
         * @brief Displays the current stage status and its child components.
         */
        void describe() override;

        /**
         * @brief Returns a formatted description of the performance schedule.
         *
         * @return Description containing the performance start and end times
         *         and the stage name.
         */
        std::string getSchedule() const;

        /**
         * @brief Returns the name of the stage.
         *
         * @return The stage name.
         */
        std::string getStageName() const;

        /**
         * @brief Sets the performance schedule for the music zone.
         *
         * @param startTime Start time of the performance.
         * @param endTime End time of the performance.
         */
        void setSchedule(std::string startTime, std::string endTime);
       
};


#endif