#include "main.h"

// MOTORS
pros::Motor left1(LEFT_1_PORT, pros::E_MOTOR_GEAR_BLUE, true, pros::E_MOTOR_ENCODER_DEGREES);
pros::Motor left2(LEFT_2_PORT, pros::E_MOTOR_GEAR_BLUE, true, pros::E_MOTOR_ENCODER_DEGREES);
pros::MotorGroup leftMotors({left1, left2});

pros::Motor right1(RIGHT_1_PORT, pros::E_MOTOR_GEAR_BLUE, false, pros::E_MOTOR_ENCODER_DEGREES);
pros::Motor right2(RIGHT_2_PORT, pros::E_MOTOR_GEAR_BLUE, false, pros::E_MOTOR_ENCODER_DEGREES);
pros::MotorGroup rightMotors({right1, right2});

pros::Motor cataMotor(CATA_PORT, pros::E_MOTOR_GEAR_RED, false, pros::E_MOTOR_ENCODER_DEGREES);

// SUBSYSTEMS
Wings wings;
Chassis chassis;
Odometry odomSys;

// SENSORS
pros::IMU imu(IMU_PORT);

// PNEUMATICS
pros::ADIDigitalOut leftWing(LEFT_WING_PORT);
pros::ADIDigitalOut rightWing(RIGHT_WING_PORT);

// MISC
Gamepad gamepad1(CONTROLLER_MASTER);
Gamepad gamepad2(CONTROLLER_PARTNER);

// CONSTANTS

const double M_PI = 3.14159265358979323846;

const int    NUM_OF_MOTORS          = 2;
const int    TICKS_PER_REVOLUTION   = 360;
const double WHEEL_DIAMETER         = 3.25;
const double WHEEL_CIRCUMFERENCE    = M_PI * WHEEL_DIAMETER;
const double GEAR_RATIO             = 0.667;

const double TURN_CONST             = 0.75;
const double CONTROLLER_DEADZONE    = 0.1;
