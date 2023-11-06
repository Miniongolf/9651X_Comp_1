#include "main.h"

class Chassis {
    public:
        // Using curly braces to avoid most vexing parse
        // Chasis position
        RobotPosition pos{0, 0, 0};

        Chassis();

        // Drive with specific powers (left side, right side)
        // Input range: [-1, 1]
        void setPowers(double leftPower, double rightPower);
        
        // Drive a specific distance
        // Distance in inches
        void driveDistance(double targetDist, double kP, bool stops = true);

        // Turns a specific angle using imu
        // Angle in degrees
        void turnToAngle(double targetAngle, bool stops = true);

        void turnRelativeAngle(double targetAngle, bool stops = true);
        
        // Stops all motors
        void brake();

        // void p2pDrive(Coord targetPos, double p2pVel, double disTolerance, double endVel, bool stopAtEnd, int timeOut);
};