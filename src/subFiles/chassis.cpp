#include "main.h"

Chassis::Chassis() {}

void Chassis::setPowers(double leftPower, double rightPower) {
    leftMotors.move(leftPower*127);
    rightMotors.move(rightPower*127);
}

// Drives a set distance away (in inches) using kP, tolerance of 1
void Chassis::driveDistance(double targetDist, double kP, bool stops) {
    Odometry tempOdom;
    double error = targetDist, currDist = 0, targetVel;
    
    while (fabs(error) > 0.5) {
        currDist = tempOdom.getLocalDistance();
        error = targetDist - currDist;
        targetVel = kP * (error - currDist);
        targetVel = std::clamp(targetVel, -1.0, 1.0);
        chassis.setPowers(targetVel, targetVel);
    }

    if (stops) {brake();}
}

void Chassis::turnAngle(double targetAngle, bool stops) {

}

void Chassis::brake() {
    leftMotors.move(0);
    rightMotors.move(0);
}