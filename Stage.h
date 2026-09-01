#ifndef STAGE_H
#define STAGE_H

#include "MusicFestivalObserver.h"
#include <string>

/**
 * @brief Represents a festival performance stage.
 *
 * Stage is a leaf participant in the Composite pattern because it
 * cannot contain child components.
 *
 * It also acts as an Observer and responds to theft and merchandise
 * alerts affecting the stage.
 */
class Stage: public MusicFestivalObserver {
    private:
        std::string currentArtist;
    public:

        /**
         * @brief Constructs a Stage for a specified artist.
         *
         * @param artist Name of the artist performing at the stage.
         */
        Stage(std::string artist);

        /**
         * @brief Attempts to add a child component.
         *
         * Stage is a leaf and therefore cannot contain children.
         *
         * @param child Child component that cannot be added.
         */
        void add(MusicFestivalObserver* child) override;

        /**
         * @brief Attempts to remove a child component.
         *
         * Stage is a leaf and therefore cannot contain children.
         *
         * @param child Child component that cannot be removed.
         */
        void remove(MusicFestivalObserver* child) override;

        /**
         * @brief Responds to theft and merchandise notifications.
         *
         * @param notice Notification received from the festival subject.
         */
        void update(const Notice& notice) override;

        /**
         * @brief Displays information about the current artist.
         */
        void describe() override;
};

#endif