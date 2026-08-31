#ifndef GATE_H
#define GATE_H

#include "MusicFestivalObserver.h"

/**
 * @brief Represents a festival entrance or stage gate.
 *
 * Gate is a leaf participant in the Composite pattern and an Observer
 * that changes its open/closed state in response to capacity and gate
 * control notifications.
 */
class Gate: public MusicFestivalObserver {
    private:
        std::string gateID;
        bool isOpen;
    public:

        /**
         * @brief Constructs a gate with an initial open/closed state.
         *
         * @param open True if the gate should initially be open; false otherwise.
         */
        Gate(bool open);

        /**
         * @brief Displays the current state of the gate.
         */
        void describe() override;

        /**
         * @brief Updates the gate state in response to a notification.
         *
         * Capacity alerts may close or open the gate depending on the
         * reported capacity, while explicit gate notifications directly
         * control its state.
         *
         * @param notice Notification received from the festival subject.
         */
        void update(const Notice& notice) override;

        /**
         * @brief Attempts to add a child component.
         *
         * Gate is a leaf and cannot contain children.
         *
         * @param child Child component that cannot be added.
         */
        void add(MusicFestivalObserver* child) override;

        /**
         * @brief Attempts to remove a child component.
         *
         * Gate is a leaf and cannot contain children.
         *
         * @param child Child component that cannot be removed.
         */
        void remove(MusicFestivalObserver* child) override;

        /**
         * @brief Changes the gate state and displays the result.
         *
         * @param open True to open the gate; false to close it.
         */
        void setAndCall(bool open);
};

#endif

