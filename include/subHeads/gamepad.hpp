#include "main.h"

class Gamepad {
    private:
        pros::controller_id_e_t controllerID;

        std::array<pros::controller_digital_e_t, 12> numToButton = {
            DIGITAL_A,
            DIGITAL_B,
            DIGITAL_X,
            DIGITAL_Y,
            DIGITAL_UP,
            DIGITAL_RIGHT,
            DIGITAL_LEFT,
            DIGITAL_DOWN,
            DIGITAL_L1,
            DIGITAL_L2,
            DIGITAL_R1,
            DIGITAL_R2
        };

        std::array<pros::controller_analog_e_t, 4> numToStick = {
            ANALOG_LEFT_X,
            ANALOG_LEFT_Y,
            ANALOG_RIGHT_X,
            ANALOG_RIGHT_Y
        };

        // Pointer array for joysticks
        std::array<double*, 4> ptrSticksArr = {
            &leftX, &leftY, &rightX, &rightY
        };

        // Pointer array for buttons (using wrapper button class)
        // std::array<Button*, 12> ptrButtonsArr = {
        //     &lb, &lt, &rb, &rt,
        //     &dpadUp, &dpadDown, &dpadLeft, &dpadRight,
        //     &x, &b, &y, &a
        // };

        std::array<Button*, 12> ptrButtonsArr = {
            &a, &b, &x, &y,
            &dpadUp, &dpadRight, &dpadLeft, &dpadDown,
            &lb, &lt, &rb, &rt,
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
