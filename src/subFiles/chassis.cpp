#include "main.h"

Chassis::Chassis() {}

void Chassis::setPowers(double leftPower, double rightPower) {
    leftMotors.move(leftPower*127);
    rightMotors.move(rightPower*127);
}

// Drives a set distance away (in inches) using kP, tolerance of 1
void Chassis::driveDistance(double targetDist, double kP, bool stops) {
    double error = targetDist, currDist = 0, targetVel;
    
    std::array<double, 2> startPoses = odomSys.getEncoderTicks();
    
    while (fabs(error) > 0.5) {
        currDist = odomSys.getLocalDistance();
        error = targetDist - currDist;
        targetVel = kP * (error - currDist);
        targetVel = std::clamp(targetVel, -1.0, 1.0);
        chassis.setPowers(targetVel, targetVel);
    }

    if (stops) {brake();}
}

void Chassis::turnToAngle(double targetAngle, bool stops) {
    double error, currAngle;

    while (error > 5) {
        currAngle = odomSys.getGlobalAngle();
        error = targetAngle - currAngle;
    }
}


void Chassis::turnRelativeAngle(double targetAngle, bool stops) {
    Odometry tempOdom;


}


void Chassis::brake() {
    leftMotors.move(0);
    rightMotors.move(0);
}