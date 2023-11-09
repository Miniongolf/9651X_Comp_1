#include "main.h"

extern void my_task_fn(void* param) {
    std::cout << "Hello" << (char*)param;
}


extern void inputs_task_fn(void* param) {
    gamepad1.getInputs();
	gamepad2.getInputs();
	pros::delay(20);
}