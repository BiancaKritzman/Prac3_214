#ifndef SOUNDTEAM_H
#define SOUNDTEAM_H

#include "MusicFestivalObserver.h"
#include <string>

class Merch;

/**
 * @brief Represents the festival sound team.
 *
 * SoundTeam is a leaf participant in the Composite pattern and an
 * Observer that reacts to schedule and merchandise notifications.
 */
class SoundTeam: public MusicFestivalObserver {
    private:
        std::string currentMessage;
        Merch* announcement;

    public:

        /**
         * @brief Constructs a SoundTeam with no current announcement.
         */
        SoundTeam();

        /**
         * @brief Responds to festival notifications.
         *
         * Schedule and merchandise notifications cause the sound team
         * to make an announcement.
         *
         * @param notice Notification received from the festival subject.
         */
        void update(const Notice& notice) override;

        /**
         * @brief Makes an announcement to festival attendees.
         *
         * @param msg Message that should be announced.
         */
        void makeAnnouncement(std::string msg);

        /**
         * @brief Attempts to add a child component.
         *
         * SoundTeam is a leaf and cannot contain children.
         *
         * @param child Child component that cannot be added.
         */
        void add(MusicFestivalObserver* child) override;

        /**
         * @brief Attempts to remove a child component.
         *
         * SoundTeam is a leaf and cannot contain children.
         *
         * @param child Child component that cannot be removed.
         */
        void remove(MusicFestivalObserver* child) override;

        /**
         * @brief Displays the most recent announcement.
         */
        void describe() override;
};

#endif