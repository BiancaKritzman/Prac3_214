#ifndef ARTIST_H
#define ARTIST_H

#include "MusicZone.h"

/**
 * @brief Represents an artist performing within a music zone.
 *
 * Artist is a specialised MusicZone containing information about
 * the performing artist and their musical genre.
 */
class Artist : public MusicZone {
    private:
        std::string genre;
        std::string artistName; 

    public:

        /**
         * @brief Constructs an artist performance zone.
         *
         * @param zoneName Name of the music zone.
         * @param isLive Whether the performance is currently live.
         * @param artistName Name of the performing artist.
         * @param genre Musical genre of the artist.
         */
        Artist(std::string zoneName, bool isLive, std::string artistName, std::string genre);

        /**
         * @brief Returns the finishing time of the performance.
         *
         * @return The scheduled finishing time.
         */
        std::string getFinishTime();

        /**
         * @brief Returns the starting time of the performance.
         *
         * @return The scheduled starting time.
         */
        std::string getStartTime();

        /**
         * @brief Displays information about the performing artist.
         */
        void describe() override;
};

#endif