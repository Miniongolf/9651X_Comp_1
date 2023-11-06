#include "main.h"

class Odometry {
    private:
        double currDist = 0;
    public:
        Odometry();
        void resetEncoderPos();
        std::array<double, 2> getEncoderTicks();
        double getLocalDistance(std::array<double, 2> startPoses);
        double getGlobalAngle();
        void setCurrDist(double distIn);
};

class RobotPosition {
    public:
        double x, y, angle;
        RobotPosition(double xIn, double yIn, double angleIn);
};