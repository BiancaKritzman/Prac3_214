#ifndef REFRESHMENTS_H
#define REFRESHMENTS_H

#include "VendorZone.h"

/**
 * @brief Represents a refreshments vendor in the festival.
 *
 * Refreshments is a leaf component within the VendorZone hierarchy
 * and stores information about the vendor and available refreshments.
 */
class Refreshments: public VendorZone {
    private:
        std::string vendorName;
        int refreshmentCount;
        std::string stolenItem;
    public:

        /**
         * @brief Constructs a refreshments vendor.
         *
         * @param zoneName Name of the vendor zone.
         * @param stalls Number of stalls allocated to the vendor.
         * @param vendorName Name of the refreshments vendor.
         * @param initialCount Initial number of refreshments available.
         */
        Refreshments(std::string zoneName, int stalls, std::string vendorName, int initialCount);
        
        /**
         * @brief Reports a theft from the refreshments vendor.
         */
        void reportTheft();

        /**
         * @brief Displays information about the refreshments vendor.
         */
        void describe() override;
};

#endif