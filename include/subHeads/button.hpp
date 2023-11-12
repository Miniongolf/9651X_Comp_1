#include "main.h"

class Button {
    private:
        bool prevState = false, currState = false;

    public:
        // Button statuses
        bool pressed, released, held;
        
        /** Button class constructor
         * \param None
         * \note Should only be used by gamepad class and not in loose code
         */
        Button();

        /** Sets the button state of pressed, held, and released
         * \param isPressed
         *        from gamepad.get_digital()
         * \returns none
         * \note Should only be used in gamepad class, not for general code.
         */
        void setStatus(bool isPressed);
};