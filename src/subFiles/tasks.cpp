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

pros::Task inputs_task(inputs_task_fn, NULL, TASK_PRIORITY_DEFAULT, TASK_STACK_DEPTH_DEFAULT, "Gamepad Input Task");
pros::Task chassis_task(chassis_task_fn, NULL, TASK_PRIORITY_DEFAULT, TASK_STACK_DEPTH_DEFAULT, "Chassis Task");

void killAllTasks() {
    inputs_task.suspend();
    gamepad1.disable();
    gamepad2.disable();
    chassis_task.suspend();
}

void startAllTasks() {
    inputs_task.resume();
    gamepad1.resume();
    gamepad2.resume();
    chassis_task.resume();
}