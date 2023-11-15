#include "main.h"

// MOTORS
pros::Motor left1(LEFT_1_PORT, pros::E_MOTOR_GEAR_BLUE, false, pros::E_MOTOR_ENCODER_DEGREES);
pros::Motor left2(LEFT_2_PORT, pros::E_MOTOR_GEAR_BLUE, false, pros::E_MOTOR_ENCODER_DEGREES);
pros::MotorGroup leftMotors({left1, left2});

pros::Motor right1(RIGHT_1_PORT, pros::E_MOTOR_GEAR_BLUE, false, pros::E_MOTOR_ENCODER_DEGREES);
pros::Motor right2(RIGHT_2_PORT, pros::E_MOTOR_GEAR_BLUE, false, pros::E_MOTOR_ENCODER_DEGREES);
pros::MotorGroup rightMotors({right1, right2});

pros::Motor cataMotor1(CATA_1_PORT, pros::E_MOTOR_GEAR_RED, false, pros::E_MOTOR_ENCODER_DEGREES);
pros::Motor cataMotor2(CATA_2_PORT, pros::E_MOTOR_GEAR_RED, false, pros::E_MOTOR_ENCODER_DEGREES);
pros::MotorGroup cataMotors({cataMotor1, cataMotor2});

// pros::Motor blockerMotor(BLOCKER_PORT, pros::E_MOTOR_GEAR_GREEN, false, pros::E_MOTOR_ENCODER_DEGREES);

// SENSORS
pros::IMU imu(IMU_PORT); // Inertial Measurement Unit sensor
// pros::Vision camera(VISION_PORT); // Vision sensor

// PNEUMATICS
pros::ADIDigitalOut leftWing(LEFT_WING_PORT);   // Left wing piston
pros::ADIDigitalOut rightWing(RIGHT_WING_PORT); // Right wing piston

// SUBSYSTEMS
Wings wings;      // Wings wrapper
Chassis chassis;  // Chassis wrapper
Odometry odomSys; // Odometry system

// MISC
Gamepad gamepad1(CONTROLLER_MASTER);  // Primary controller
Gamepad gamepad2(CONTROLLER_PARTNER); // Secondary controller

// CONSTANTS
const double PI = 3.141592653589793;
const int    NUM_OF_MOTORS          = leftMotors.size();
const int    TICKS_PER_REVOLUTION   = 360;
const double WHEEL_DIAMETER         = 3.25;
const double WHEEL_CIRCUMFERENCE    = PI * WHEEL_DIAMETER;
const double GEAR_RATIO             = 0.667;

const double TURN_CONST             = 0.75;
const double CONTROLLER_DEADZONE    = 0.1;
