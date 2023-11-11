#include "main.h"

class Gamepad {
    private:
        pros::controller_id_e_t controllerID;

    public:
        double leftX, leftY, rightX, rightY;
        Button a, b, x, y;
        Button dpadUp, dpadRight, dpadLeft, dpadDown;
        Button lb, lt, rb, rt;

        std::array<double*, 4> ptrSticksArr = {
            &leftX, &leftY, &rightX, &rightY
        };

        std::array<Button*, 12> ptrButtonsArr = {
            &lb, &lt, &rb, &rt,
            &dpadUp, &dpadDown, &dpadLeft, &dpadRight,
            &x, &b, &y, &a
        };

        Gamepad(pros::controller_id_e_t id);
        void getInputs();
};
