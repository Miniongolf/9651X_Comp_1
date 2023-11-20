#pragma once
#include "main.h"

class Odometry {
    private:
        double currDist = 0;
    public:
        /** Odometry class constructor
         * \param None
         * \note Should only be called once in `main.h`
         */
        Odometry();

        /**
         * Initializes odometry system
         * Resets motor encoder positions and imu heading
         * \param None
         * \returns `None`
         * \note Should only be run in robot initialization
         */
        void init();

        /**
         * \note DEPRECIATED
         */
        void resetEncoderPos();

        /**
         * Returns motor encoder positions
         * Averages left and right separately
         * \param None
         * \returns double array of left encoder pos, right encoder pos
         */
        std::array<double, 2> getEncoderTicks();

        /**
         * Returns the distance traveled since starting position
         * \param startPoses
         *        Starting position calculated by getEncoderTicks()
         * \returns Distance traveled (in inches)
         * 
         */
        double getLocalDistance(std::array<double, 2> startPoses);

        /**
         * Returns robot heading (calculated using imu)
         * \param None
         * \returns Robot heading (in degrees)
         */
        double getHeading();

        /**
         * \note DEPRECIATED
         */
        void setCurrDist(double distIn);
};