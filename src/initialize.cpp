#include "main.h"

/**
 * Runs initialization code. This occurs as soon as the program is started.
 *
 * All other competition modes are blocked by initialize; it is recommended
 * to keep execution time for this mode under a few seconds.
 */
void initialize() {
    // Initialize brain screen display
    pros::lcd::initialize();

    // Initialize odometry
    odomSys.init();
    
    // Reset catapult encoder position
    cataMotor.tare_position();
    
    // Tuck in wings
    // wings.setPosition(-1, -1);

    // pros::Task my_task (my_task_fn, (void*)"PROS", TASK_PRIORITY_DEFAULT,
    //             TASK_STACK_DEPTH_DEFAULT, "My Task");
}

