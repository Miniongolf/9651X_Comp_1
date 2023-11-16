#include "main.h"

class Chassis {
    public:
        // Using curly braces to avoid most vexing parse
        // Chassis position
        RobotPosition pos{0, 0, 0};

        double leftPower, rightPower;

        Chassis();

        /** Sets the drivetrain powers for left and right side
         * \param leftPower
         *        Left side power [-1, 1]
         * \param rightPower
         *        Right side power [-1, 1]
         * 
         * \returns none
         */
        void setPowers(double leftPowerIn, double rightPowerIn);
        
        /** Drives the chassis using the leftPower and rightPower properties
         * \param None
         * 
         * \returns `None`
         * \note Should only be called in chassis drive task.
         */
        void drivePowers();

        /** Drives a set linear distance using kP
         * \param targetDist
         *        Distance to drive (in inches)
         * \param kP
         *        Proportional gain
         * \param stops
         *        Stop at target or keep driving
         * 
         * \returns pressed, held, released
         * \note Blocking
         */
        void driveDistance(double targetDist, double kP, bool stops = true);

        /** Turns to a specific heading using imu (in degrees)
         * \param targetHeading
         *        Heading to turn to (in degrees)
         * \param stops
         *        Stop at heading or keep going
         * \note Blocking
         */
        void turnToHeading(double targetHeading, double kP, bool stops = true);

        /** Turns a set angle from starting position
         * \param targetAngle
         *        Angle to turn clockwise from start (in degrees)
         * \param stops
         *        Stop at end or keep going
         * \note Blocking
         */
        void turnRelativeAngle(double targetAngle, double kP, bool stops = true);
        
        /** Stops all motors
         * \param None
         */
        void brake();

        // void p2pDrive(Coord targetPos, double p2pVel, double disTolerance, double endVel, bool stopAtEnd, int timeOut);
};