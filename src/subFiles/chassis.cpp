#include "main.h"
#include "chassis.hpp"

Chassis::Chassis() {}

void Chassis::drive(double leftPower, double rightPower, int runtime, bool stops) {
    leftMotors.move(leftPower*127);
    rightMotors.move(rightPower*127);
    pros::delay(runtime);
    if (stops) {brake();} 
}

// Drives a set distance away (in inches) using kP, tolerance of 1
void Chassis::driveDistance(double targetDist, double kP, bool stops) {
    Odometry tempOdom;
    double error, currDist = 0, targetVel;
    
    currDist = tempOdom.getLocalDistance();
    
    error = targetVel - currDist;

    targetVel = kP * (error - currDist);
    targetVel = std::clamp(targetVel, -1.0, 1.0);
}

void Chassis::turnAngle(double targetAngle, bool stops) {

}

void Chassis::brake() {
    leftMotors.move(0);
    rightMotors.move(0);
}