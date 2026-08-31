#ifndef SECURITY_H
#define SECURITY_H

#include "MusicFestivalObserver.h"
#include <string>

class Zones;

/**
 * @brief Represents the festival security team.
 *
 * Security is a leaf participant in the Composite pattern because it
 * does not contain child festival components.
 *
 * Security also acts as an Observer by responding to theft reports
 * and dispatching security to the affected zone.
 */
class Security: public MusicFestivalObserver {
    private:
        int gaurdCount;
        std::string currentZone;
        Zones* eventRoot;

    public:

        /**
         * @brief Constructs a Security team.
         *
         * @param guards Number of guards available to the security team.
         * @param zone Zone where the security team is initially located.
         * @param root Root zone used to send notifications after security
         *             responds to an incident.
         *
         * The root pointer is non-owning. Security uses the root to send
         * notifications but does not manage its lifetime.
         */
        Security(int guards, std::string zone, Zones* root);

        /**
         * @brief Responds to a festival notification.
         *
         * Security responds to theft reports by dispatching security to
         * the zone identified by the notification.
         *
         * @param notice Notification received from the festival subject.
         */
        void update(const Notice& notice) override;

        /**
         * @brief Dispatches security to a specified zone.
         *
         * @param zoneName Name or identifier of the zone receiving security.
         */
        void dispatchToZone(std::string zoneName);

        /**
         * @brief Attempts to add a child component.
         *
         * Security is a leaf and therefore cannot contain children.
         * This operation has no effect.
         *
         * @param child Child component that cannot be added.
         */
        void add(MusicFestivalObserver* child) override;

        /**
         * @brief Attempts to remove a child component.
         *
         * Security is a leaf and therefore cannot contain children.
         * This operation has no effect.
         *
         * @param child Child component that cannot be removed.
         */
        void remove(MusicFestivalObserver* child) override;

        /**
         * @brief Displays the current security team status.
         */
        void describe() override;
};

#endif