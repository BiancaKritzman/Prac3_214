#ifndef VENDORZONE_H
#define VENDORZONE_H

#include "Zones.h"

/**
 * @brief Represents a festival zone containing vendor stalls.
 *
 * VendorZone extends Zones with information about the number of
 * stalls available in the vendor area.
 */
class VendorZone : public Zones {
    private:
        int totalStalls;
    public:

        /**
         * @brief Constructs a vendor zone.
         *
         * @param name Name of the vendor zone.
         * @param stalls Number of vendor stalls in the zone.
         */
        VendorZone(std::string name, int stalls);

        /**
         * @brief Displays information about the vendor zone.
         */
        void describe() override;
};

#endif