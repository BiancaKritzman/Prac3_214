#ifndef CROWD_H
#define CROWD_H

#include "MusicZone.h"

/**
 * @brief Represents the crowd and capacity of a music zone.
 *
 * Crowd extends MusicZone with maximum and current capacity
 * information and reports when the zone is approaching or exceeding
 * its capacity.
 */
class Crowd : public MusicZone {
    private:
        int maxCapacity;
        int currentCapacity;
    public:
        
        /**
         * @brief Constructs a crowd capacity tracker.
         *
         * @param name Name of the music zone.
         * @param isLive Whether the zone is currently live.
         * @param maxCap Maximum allowed capacity.
         */
        Crowd(std::string name, bool isLive, int maxCap);

        /**
         * @brief Sets the maximum capacity of the crowd zone.
         *
         * @param capacity New maximum capacity.
         */
        void setCapacity(int capacity);

        /**
         * @brief Returns the maximum capacity of the crowd zone.
         *
         * @return Maximum allowed capacity.
         */
        int getCapacity();

        /**
         * @brief Displays the current crowd capacity status.
         */
        void describe() override;
};

#endif