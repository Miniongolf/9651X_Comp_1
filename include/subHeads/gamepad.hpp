#pragma once
#include "main.h"

class Gamepad {
    private:
        pros::controller_id_e_t controllerID;

        /*
        std::array<pros::controller_analog_e_t, 4> numToStick = {
            ANALOG_LEFT_X,
            ANALOG_LEFT_Y,
            ANALOG_RIGHT_X,
            ANALOG_RIGHT_Y
        };

        // std::array<pros::controller_digital_e_t, 12> numToButton = {
        //     DIGITAL_A,
        //     DIGITAL_B,
        //     DIGITAL_X,
        //     DIGITAL_Y,
        //     DIGITAL_UP,
        //     DIGITAL_RIGHT,
        //     DIGITAL_LEFT,
        //     DIGITAL_DOWN,
        //     DIGITAL_L1,
        //     DIGITAL_L2,
        //     DIGITAL_R1,
        //     DIGITAL_R2
        // };

        std::array<pros::controller_digital_e_t, 12> numToButton = {
            DIGITAL_L1,
            DIGITAL_L2,
            DIGITAL_R1,
            DIGITAL_R2,
            DIGITAL_UP,
            DIGITAL_DOWN,
            DIGITAL_LEFT,
            DIGITAL_RIGHT,
            DIGITAL_X,
            DIGITAL_B,
            DIGITAL_Y,
            DIGITAL_A
        };
        */

        // Pointer array for joysticks
        std::array<double*, 4> ptrSticksArr = {
            &leftX, &leftY, &rightX, &rightY
        };

        // std::array<Button*, 12> ptrButtonsArr = {
        //     &a, &b, &x, &y,
        //     &dpadUp, &dpadRight, &dpadLeft, &dpadDown,
        //     &lb, &lt, &rb, &rt,
        // };

        // Pointer array for buttons (using wrapper button class)
        std::array<Button*, 12> ptrButtonsArr = {
            &lb, &lt, &rb, &rt,
            &dpadUp, &dpadDown, &dpadLeft, &dpadRight,
            &x, &b, &y, &a
        };

    public:
        double leftX, leftY, rightX, rightY;
        Button lb, lt, rb, rt;
        Button dpadUp, dpadDown, dpadLeft, dpadRight;
        Button x, b, y, a;

        bool disabled;

        /** Gamepad class constructor
         * \param id
         *        MASTER or PARTNER
         */
        Gamepad(pros::controller_id_e_t id);

        /** 
         * Gets the inputs from the gamepad
         * \param None
         * \note Should run in task
         */
        void getInputs();

        /** 
         * Sets all gamepad inputs to 0 or false (except cancel button)
         * \param None
         * \note Used when running semi auton
         */
        void disable();

        /** 
         * Sets disabled to false
         * \param None
         * \note Used every time we cancel or end auton/semiauton
         */
        void resume();
};
