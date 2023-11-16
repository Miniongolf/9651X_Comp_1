#include "main.h"

std::array<double, 2> processSticks() {
	enum speed_modes {
		speed = 0,
		precision
	};

	speed_modes speedMode;

	double leftVel, rightVel, highVel;
	double targetLeftVel = 0, targetRightVel = 0;

	leftVel = gamepad1.leftY + (gamepad1.rightX*TURN_CONST);
	rightVel = gamepad1.leftY - (gamepad1.rightX*TURN_CONST);

	// Pressed = precision, released = speed
	speedMode = static_cast<speed_modes> (gamepad1.rb.held);

	leftVel = gamepad1.leftY + (gamepad1.rightX*TURN_CONST);
	rightVel = gamepad1.leftY - (gamepad1.rightX*TURN_CONST);
	
	highVel = std::max(fabs(leftVel), fabs(rightVel));
	
	// Normalize to [-1, 1]
	if (highVel > 1 || speedMode == precision) {
		leftVel /= highVel;
		rightVel /= highVel;
	}

	// Slow down the chassis to half speed if drive is on precision mode
	if (speedMode == precision) {
		leftVel /= 2;
		rightVel /= 2;
	}

	return {leftVel, rightVel};
}

/**
 * Runs the operator control code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the operator
 * control mode.
 *
 * If no competition control is connected, this function will run immediately
 * following initialize().
 *
 * If the robot is disabled or communications is lost, the
 * operator control task will be stopped. Re-enabling the robot will restart the
 * task, not resume it from where it left off.
 */
void opcontrol() {
    pros::lcd::print(1, "opmode");

	pros::Task inputs_task(inputs_task_fn, "Gamepad Input Task");
	pros::Task chassis_task(chassis_task_fn, "Chassis Task");

	double leftVel, rightVel, highVel;
	double targetLeftVel = 0, targetRightVel = 0;

	bool usingAccel = false;

	enum speed_modes {
		speed = 0,
		precision
	};

	speed_modes speedMode;

	while (true) {
		std::array<double, 2>vels = processSticks();
		double leftVel = vels[0], rightVel = vels[1];

		chassis.setPowers(leftVel, rightVel);

		if (gamepad1.a.pressed) {
			autonomous();
		}

		if (gamepad1.rt) {
			cata.runContinuous();
		}
		
		pros::delay(20); // Delay to prevent from overdrawing cpu resources
	}
}