#ifndef MUSICFESTIVALOBSERVER_H
#define MUSICFESTIVALOBSERVER_H

#include <iostream>
#include <string>

/**
 * @brief Represents a notification sent to observers in the festival system.
 *
 * A Notice contains information about an event occurring at the festival,
 * such as a theft, capacity alert, or schedule update.
 */
struct Notice {
    std::string type;       // e.g. "Theft"
    std::string zoneID; 
    std::string detail;     // e.g. The artist's name or the stolen item
    int currentCapacity;
    int threshold;

    /**
     * @brief Constructs a Notice describing a festival event.
     *
     * @param type Type of notification being generated.
     * @param zoneID Identifier of the zone associated with the notification.
     * @param detail Additional information about the notification.
     * @param currentCapacity Current capacity of the relevant zone.
     * @param threshold Capacity threshold associated with the notification.
     */
    Notice(std::string type, std::string zoneID, std::string detail,
           int currentCapacity = 0, int threshold = 0)
        : type(std::move(type)), zoneID(std::move(zoneID)), detail(std::move(detail)),
          currentCapacity(currentCapacity), threshold(threshold) {}
    
};

/**
 * @brief Common interface for festival components that can receive notifications.
 *
 * This class acts as the Component participant in the Composite design pattern.
 * Both leaf objects and composite Zones can be treated uniformly through this
 * interface.
 *
 * It also provides the interface used by the Observer pattern for receiving
 * festival notifications.
 */
class MusicFestivalObserver {
    public:

        /**
         * @brief Destroys the observer/component.
         *
         * The destructor is virtual so that derived objects can be safely
         * destroyed through a MusicFestivalObserver pointer.
         */
        virtual ~MusicFestivalObserver() = default;

        /**
         * @brief Adds a child component.
         *
         * Design decision:
         * The add operation is included in the common Component interface so
         * that both Composite objects and leaf objects can be treated uniformly.
         * Composite objects use this operation to add children, while leaf
         * objects implement it as a no-op because they cannot contain children.
         *
         * This allows clients to work with both leaves and composites through
         * the same MusicFestivalObserver interface without needing to know the
         * concrete type of the object.
         *
         * @param child Component to add.
         */
        virtual void add(MusicFestivalObserver* child) = 0;

        /**
         * @brief Removes a child component.
         *
         * Design decision:
         * Leaf classes implement this operation even though they cannot have
         * children. This maintains a consistent interface for all components
         * in the Composite hierarchy. A leaf therefore provides a no-op
         * implementation rather than requiring clients to check whether an
         * object is a leaf or composite before calling remove().
         *
         * @param child Component to remove.
         */
        virtual void remove(MusicFestivalObserver* child) = 0;

         /**
         * @brief Receives a notification from a subject.
         *
         * @param notice Notification containing information about the event.
         */
        virtual void update(const Notice& notice) = 0;

        /**
         * @brief Displays a description of the component.
         *
         * Derived classes provide their own description.
         */
        virtual void describe() = 0;
};



#endif
