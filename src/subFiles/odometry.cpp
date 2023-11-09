#include "main.h"

// Odometry class constructor
Odometry::Odometry() {}

// Initializes the odometry system
void Odometry::init() {
    // imu.reset();
    leftMotors.tare_position();
    rightMotors.tare_position();
}

// Reset the encoder ticks to 0
void Odometry::resetEncoderPos() {
    leftMotors.tare_position();
    rightMotors.tare_position();
}

std::array<double, 2> Odometry::getEncoderTicks() {
    std::vector<double> leftPositions, rightPositions;

    leftPositions = leftMotors.get_positions();
    rightPositions = rightMotors.get_positions();

    double leftAvgPos, rightAvgPos;

    for (int i = 0; i < NUM_OF_MOTORS; i++) {
        leftAvgPos += leftPositions[i];
        rightAvgPos += rightPositions[i];

        std::cout << leftPositions[i] << ' ' << rightPositions[i] << ' ';
    }
    std::cout << '\n';

    leftAvgPos /= (NUM_OF_MOTORS);
    rightAvgPos /= (NUM_OF_MOTORS);

    return {leftAvgPos, rightAvgPos};
}

// Get forwards distance since last reset
double Odometry::getLocalDistance(std::array<double, 2> startPoses) {
    std::array<double, 2> encoderPoses = getEncoderTicks();

    double leftTicks = encoderPoses[0] - startPoses[0];
    double rightTicks = encoderPoses[1] - startPoses[1];
    
    double avgTicks = (leftTicks + rightTicks) / 2;

    double currDist = (avgTicks / TICKS_PER_REVOLUTION) * WHEEL_CIRCUMFERENCE * GEAR_RATIO;

    return currDist;
}

// Get global imu angle
double Odometry::getHeading() {
    // return imu.get_yaw();
    return 0;
}

// Set the odometry's current registered distance
void Odometry::setCurrDist(double distIn) {
    currDist = distIn;
}