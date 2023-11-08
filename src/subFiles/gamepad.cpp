#include "main.h"

Gamepad::Gamepad(pros::controller_id_e_t id) {
    controllerID = id;
}

void Gamepad::getInputs() {
    pros::Controller controller(controllerID);

    // Get the input value for the stick axes
    for (int i = 0; i <= 3; i++) {
        pros::controller_analog_e_t stick = static_cast<pros::controller_analog_e_t>(i);
        *ptrSticksArr[i] = controller.get_analog(stick)/127.0;
        *ptrSticksArr[i] = *ptrSticksArr[i];

        // Cross deadzone
        if (fabs(*ptrSticksArr[i]) <= CONTROLLER_DEADZONE) {*ptrSticksArr[i] = 0;}
    }

    // Get the status for the buttons
    for (int i = 6; i <= 17; i++) {
        pros::controller_digital_e_t button = static_cast<pros::controller_digital_e_t>(i);
        (*ptrButtonsArr[i]).setStatus(controller.get_digital(button));
    }
}
