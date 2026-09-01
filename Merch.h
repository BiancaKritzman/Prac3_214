#ifndef MERCH_H
#define MERCH_H

#include "MusicFestivalObserver.h"
#include "VendorZone.h"
#include <string>

/**
 * @brief Represents a merchandise vendor for an artist.
 *
 * Merch is a leaf component in the festival Composite hierarchy.
 * It also acts as an Observer, although it currently ignores
 * incoming notifications.
 */
class Merch: public VendorZone {
    private:
        std::string artistName;

    public:

        /**
         * @brief Constructs a merchandise vendor.
         *
         * @param zoneName Name of the vendor zone.
         * @param stalls Number of stalls allocated to merchandise.
         * @param artist Name of the artist whose merchandise is sold.
         */
        Merch(std::string zoneName, int stalls, std::string artist);

        /**
         * @brief Requests an announcement that merchandise is available.
         */
        void requestAnnouncement();

        /**
         * @brief Receives a festival notification.
         *
         * Merch currently does not react to any notification types.
         *
         * @param notice Notification received from the festival subject.
         */
        void update(const Notice& notice) override;

        /**
         * @brief Attempts to add a child component.
         *
         * Merch is a leaf and cannot contain children.
         *
         * @param child Child component that cannot be added.
         */
        void add(MusicFestivalObserver* child) override;

        /**
         * @brief Attempts to remove a child component.
         *
         * Merch is a leaf and cannot contain children.
         *
         * @param child Child component that cannot be removed.
         */
        void remove(MusicFestivalObserver* child) override;

        /**
         * @brief Displays the merchandise vendor information.
         */
        void describe() override;
};

#endif