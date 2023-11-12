#include "main.h"

Chassis::Chassis() {}

void Chassis::setPowers(double leftPower, double rightPower) {
    leftMotors.move(leftPower*127);
    rightMotors.move(rightPower*127);
}

void Chassis::driveDistance(double targetDist, double kP, bool stops) {
    double error = targetDist, currDist = 0, targetVel;
    
    std::array<double, 2> startPoses = odomSys.getEncoderTicks();
    
    while (fabs(error) > 0.5) {
        currDist = odomSys.getLocalDistance(startPoses);
        error = targetDist - currDist;
        targetVel = kP * (error - currDist);
        targetVel = std::clamp(targetVel, -1.0, 1.0);
        chassis.setPowers(targetVel, targetVel);
    }

    if (stops) {brake();}
}

void Chassis::turnToHeading(double targetAngle, bool stops) {
    double error, currAngle;

    while (error > 5) {
        currAngle = odomSys.getHeading();
        error = targetAngle - currAngle;
        // Implement turning logic
    }
}

void Chassis::turnRelativeAngle(double targetAngle, bool stops) {
    double error;
    double startAngle = odomSys.getHeading(), turnedAngle;

    while (error > 5) {
        turnedAngle = odomSys.getHeading() - startAngle;
        error = startAngle - turnedAngle;
        // Implement turning logic
    }
}

void Chassis::brake() {
    leftMotors.move(0);
    rightMotors.move(0);
}