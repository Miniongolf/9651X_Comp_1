#include "main.h"

enum speed_modes {
	speed = 0,
	precision
};

speed_modes speedMode;

/**
 * Processes the inputs from the gamepad sticks and converts them to movement powers. 
 */
std::array<double, 2> processSticks() {
	double forwardsVel, turnVel;

	forwardsVel = gamepad1.leftY;
	turnVel = gamepad1.rightX*TURN_CONST;

	return {forwardsVel, turnVel};
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
    pros::lcd::print(1, "teleop");

	// Start tasks
    startAllTasks();

	double forwardsVel, turnVel;
	double highVel, leftVel, rightVel;

	while (true) {
		std::array<double, 2>vels = processSticks();
		forwardsVel = vels[0], turnVel = vels[1];

		// Pressed = precision, released = speed
		if (gamepad1.rb) {speedMode = precision;}
		else {speedMode = speed;}

		// Slow down the chassis to half speed if drive is on precision mode
		if (speedMode == precision) {
			forwardsVel /= 2;
			turnVel /= 2;
		}

		if (gamepad1.a.pressed) {
			std::cout << "a press\n";
			killAllTasks();
			autonomous();
		}

		if (gamepad1.y) {cata.runContinuous();}
		else {cata.stop();}
		
		if (gamepad1.lt) {wings.setPosition(1,1);}
		else {wings.setPosition(-1,-1);}

		leftVel = forwardsVel + turnVel;
		rightVel = forwardsVel - turnVel;
		highVel = std::max(fabs(leftVel), fabs(rightVel));

		// Normalize to [-1, 1]
		if (highVel > 1) {
			leftVel /= highVel;
			rightVel /= highVel;
		}

		// Update the chassis's member var powers
		chassis.setPowers(leftVel, rightVel);

		pros::delay(20); // Delay to prevent from overdrawing cpu resources
	}
}