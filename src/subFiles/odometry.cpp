#include "main.h"

// Odometry class constructor (no args)
Odometry::Odometry() {}

// Robot Position class constructor (x, y, angle)
RobotPosition::RobotPosition(double xIn, double yIn, double angleIn) {
    x = xIn;
    y = yIn;
    angle = angleIn;
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

    leftAvgPos /= (NUM_OF_MOTORS*2);
    rightAvgPos /= (NUM_OF_MOTORS*2);

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
double Odometry::getGlobalAngle() {
    return imu.get_yaw();
}

// Set the odometry's current registered distance
void Odometry::setCurrDist(double distIn) {
    currDist = distIn;
}