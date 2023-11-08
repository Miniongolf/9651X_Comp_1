#include "main.h"

class Odometry {
    private:
        double currDist = 0;
    public:
        Odometry();
        void init();
        void resetEncoderPos();
        std::array<double, 2> getEncoderTicks();
        double getLocalDistance(std::array<double, 2> startPoses);
        double getHeading();
        void setCurrDist(double distIn);
};