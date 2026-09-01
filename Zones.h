#ifndef ZONES_H
#define ZONES_H

#include "MusicFestivalObserver.h"
#include <vector>
#include <string>

/**
 * @brief Represents a festival zone that can contain other components.
 *
 * Zones is the Composite participant in the Composite design pattern.
 * It allows individual festival components and groups of components
 * to be treated through the same MusicFestivalObserver interface.
 *
 * Zones also acts as a Subject in the Observer pattern by maintaining
 * a list of observers and notifying them when a festival event occurs.
 */
class Zones: public MusicFestivalObserver {
    private:
        std::string zoneName;

        /**
         * @brief Stores the child components owned by this Zone.
         *
         * Design decision:
         * The Zone owns its child components because the Zone represents the
         * parent in the Composite hierarchy. When a child is added, ownership
         * is transferred to the Zone. This allows the Zone to manage the
         * lifetime of its children and delete them when the Zone is destroyed.
         *
         * This ownership model prevents the parent composite from leaving
         * dynamically allocated child components without an owner.
         */
        std::vector<MusicFestivalObserver*> children;    

        /**
         * @brief Stores pointers to observers that should receive notifications.
         *
         * Design decision:
         * The observer list is non-owning because Zones is responsible only for
         * notifying observers, not for managing their lifetimes. An observer may
         * exist independently of the Zone that is notifying it, so Zones must not
         * delete the objects stored in this list.
         *
         * Observers must remain alive while they are registered and should be
         * detached before they are destroyed.
         */
        std::vector<MusicFestivalObserver*> observerList;  

    public:

        /**
         * @brief Constructs a festival zone.
         *
         * @param name Name of the zone.
         */
        Zones(std::string name);

        /**
         * @brief Destroys the zone and its owned children.
         *
         * All children currently owned by the zone are deleted.
         * Observers are not deleted because observerList contains
         * non-owning pointers.
         */
        ~Zones() override;

        /**
         * @brief Adds a child to the zone.
         *
         * Ownership of the child is transferred to this zone. The zone
         * becomes responsible for deleting the child when it is destroyed.
         *
         * @param child Component to add. A nullptr is ignored.
         */
        void add(MusicFestivalObserver* child) override;

        /**
         * @brief Removes a child from the zone.
         *
         * Removing a child releases the zone's ownership without deleting
         * the child. The caller becomes responsible for the child's lifetime.
         *
         * @param child Component to remove.
         */
        void remove(MusicFestivalObserver* child) override;

        /**
         * @brief Registers an observer to receive future notifications.
         *
         * The observer pointer is non-owning. Zones stores the pointer only
         * for notification purposes and does not delete the observer.
         * The observer must remain alive while registered and should be
         * detached before it is destroyed.
         *
         * @param observer Observer to register.
         */
        void attach(MusicFestivalObserver* observer);

        /**
         * @brief Removes an observer from the notification list.
         *
         * Removing the observer does not destroy it because Zones does not
         * own objects stored in observerList.
         *
         * @param observer Observer to remove.
         */
        void detach(MusicFestivalObserver* observer);

        /**
         * @brief Sends a notification to all registered observers.
         *
         * Each registered observer receives the supplied Notice through
         * its update operation.
         *
         * @param notice Notification to broadcast.
         */
        void notify(const Notice& notice);

        /**
         * @brief Receives a notification and forwards it to observers.
         *
         * @param notice Notification to forward.
         */
        void update(const Notice& notice) override;

        /**
         * @brief Displays this zone and recursively describes its children.
         */
        void describe() override;
};

#endif