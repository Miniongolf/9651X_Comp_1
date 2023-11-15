#include "main.h"

Gamepad::Gamepad(pros::controller_id_e_t id) {
    controllerID = id;
}

void Gamepad::getInputs() {
    pros::Controller controller(controllerID);

    for (int i = 0; i < 4; i++) {
        *ptrSticksArr[i] = controller.get_analog(numToStick[i])/127.0;
        if (fabs(*ptrSticksArr[i]) <= CONTROLLER_DEADZONE) {*ptrSticksArr[i] = 0;}
    }
    
    for (int i = 0; i < 12; i++) {
        (*ptrButtonsArr[i]).setStatus(controller.get_digital(numToButton[i]));
    }
    
    // // Get the input value for the stick axes
    // for (int i = 0; i < 4; i++) {
    //     pros::controller_analog_e_t stick = static_cast<pros::controller_analog_e_t>(i);
    //     *ptrSticksArr[i] = controller.get_analog(stick)/127.0;

    //     // Cross deadzone
    //     if (fabs(*ptrSticksArr[i]) <= CONTROLLER_DEADZONE) {*ptrSticksArr[i] = 0;}
    // }

    // // Get the status for the buttons
    // for (int i = 0; i < 12; i++) {
    //     /** NOTE: add 6 to i to match the pros::controller_digital_e_t enum in misc.h */
    //     pros::controller_digital_e_t button = static_cast<pros::controller_digital_e_t>(i+6);
    //     (*ptrButtonsArr[i]).setStatus(controller.get_digital(button));
    // }
}