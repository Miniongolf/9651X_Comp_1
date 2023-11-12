#include "main.h"

class Gamepad {
    private:
        pros::controller_id_e_t controllerID;

        // Pointer array for joysticks
        std::array<double*, 4> ptrSticksArr = {
            &leftX, &leftY, &rightX, &rightY
        };

        // Pointer array for buttons (using wrapper button class)
        std::array<Button*, 12> ptrButtonsArr = {
            &lb, &lt, &rb, &rt,
            &dpadUp, &dpadDown, &dpadLeft, &dpadRight,
            &x, &b, &y, &a
        };
    public:
        double leftX, leftY, rightX, rightY;
        Button a, b, x, y;
        Button dpadUp, dpadRight, dpadLeft, dpadDown;
        Button lb, lt, rb, rt;

        /** Gamepad class constructor
         * \param id
         *        MASTER or PARTNER
         */
        Gamepad(pros::controller_id_e_t id);

        /** 
         * Gets the inputs from the gamepad
         * \param none
         * \note Should run in task
         */
        void getInputs();
};
