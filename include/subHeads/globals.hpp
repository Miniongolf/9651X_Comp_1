#pragma once
#include "main.h"

/* #region define ports */
// MOTOR PORTS
#define LEFT_1_PORT -11
#define LEFT_2_PORT -2
#define RIGHT_1_PORT 12
#define RIGHT_2_PORT 13

#define CATA_1_PORT 4
#define CATA_2_PORT -1

// #define BLOCKER_PORT 5

// PNEUMATICS PORTS
#define LEFT_WING_PORT 'A' // Pneumatics port for left wing
#define RIGHT_WING_PORT 'H' // Pneumatics port for right wing

// SENSOR PORTS
#define IMU_PORT 17
// #define VISION_PORT 9
/* #endregion define ports */

// MOTORS
extern pros::Motor left1;
extern pros::Motor left2;
extern pros::MotorGroup leftMotors; // Left side drivetrain motor group

extern pros::Motor right1;
extern pros::Motor right2;
extern pros::MotorGroup rightMotors; // Right side drivetrain motor group

extern pros::Motor cataMotor1;
extern pros::Motor cataMotor2;
extern pros::MotorGroup cataMotors; // Catapult motor group

// extern pros::Motor blockerMotor; // Blocker motor

// SENSORS
extern pros::IMU imu; // Inertial Measurement Unit
// extern pros::Vision camera; // Vision sensor

// PNEUMATICS
extern pros::ADIDigitalOut leftWing; // Pneumatics for left wing
extern pros::ADIDigitalOut rightWing; // Pneumatics for right wing

// SUBSYSTEMS
extern Cata cata;
extern Wings wings;
extern Chassis chassis;
extern Odometry odomSys;

// MISC
extern Gamepad gamepad1; // Primary controller
extern Gamepad gamepad2; // Secondary controller

// CONSTANTS
/*
#define NUM_OF_MOTORS (2) // Number of motors per side of chassis
#define PI (3.14159265358979323846) // Literally just pi
#define TURN_CONST (0.75) // Turning speed multiplier
#define CONTROLLER_DEADZONE (0.1) // Controller deadzone (cross)
#define TICKS_PER_REVOLUTION (360) // Number of encoder ticks per full motor revolution
#define WHEEL_DIAMETER (3.25) // Wheel diameter in inches
#define WHEEL_CIRCUMFERENCE (M_PI * WHEEL_DIAMETER) // Wheel circumference in inches
#define GEAR_RATIO (0.667) // Motor to wheel gear ratio
*/

extern const double PI;                     // Pi (why does cmath M_PI not work bruh)
extern const int    NUM_OF_MOTORS;          // Number of motors per side of chassis
extern const int    TICKS_PER_REVOLUTION;   // Number of encoder ticks per full motor revolution
extern const double WHEEL_DIAMETER;         // Wheel diameter (inches)
extern const double WHEEL_CIRCUMFERENCE;    // Wheel circumference (inches)
extern const double GEAR_RATIO;             // Wheel to motor gear ratio

extern const double TURN_CONST;             // Turning speed multiplier
extern const double CONTROLLER_DEADZONE;    // Controller deadzone (cross)