#include "main.h"

void inputs_task_fn(void* param) {
    while (true) {
        gamepad1.getInputs();
        gamepad2.getInputs();

        pros::delay(20);
    }
}

void chassis_task_fn(void* param) {
    while (true) {
        chassis.drivePowers();
        
        pros::delay(20);
    }
}