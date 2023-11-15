#include "main.h"

Chassis::Chassis() {}

void Chassis::setPowers(double leftPower, double rightPower) {
    leftMotors.move(leftPower*127);
    rightMotors.move(rightPower*127);
}

void Chassis::driveDistance(double targetDist, double kP, bool stops) {
    double error = targetDist, currDist = 0, targetVel;

    int timeout = 1000 + targetDist * 1000;
    int startTime = pros::millis(), endTime = startTime + timeout;
    
    std::array<double, 2> startPoses = odomSys.getEncoderTicks();
    
    // Stop when at target or on timeout
    while (fabs(error) > 0.5 && pros::millis() < endTime) {
        currDist = odomSys.getLocalDistance(startPoses);
        error = targetDist - currDist;
        targetVel = kP * (error - currDist);
        targetVel = std::clamp(targetVel, -1.0, 1.0);
        chassis.setPowers(targetVel, targetVel);
    }

    if (stops) {brake();}
}

void Chassis::turnToHeading(double targetAngle, double kP, bool stops) {
    double error, currAngle, targetVel;

    int timeout = targetAngle * 50;
    int startTime = pros::millis(), endTime = startTime + timeout;

    while (error > 5 && pros::millis() < endTime) {
        currAngle = odomSys.getHeading();
        error = targetAngle - currAngle;
        targetVel = kP * (error - currAngle);
        targetVel = std::clamp(targetVel, -1.0, 1.0);
        chassis.setPowers(targetVel, -targetVel);
    }
}

void Chassis::turnRelativeAngle(double targetAngle, double kP, bool stops) {
    double error, currAngle, targetVel;
    double startAngle = odomSys.getHeading(), turnedAngle;

    int timeout = targetAngle * 50;
    int startTime = pros::millis(), endTime = startTime + timeout;

    while (error > 5 && pros::millis() < endTime) {
        turnedAngle = odomSys.getHeading() - startAngle;
        error = startAngle - turnedAngle;
        targetVel = kP * (error - turnedAngle);
        targetVel = std::clamp(targetVel, -1.0, 1.0);
        chassis.setPowers(targetVel, -targetVel);
    }
}

void Chassis::brake() {
    leftMotors.move(0);
    rightMotors.move(0);
}