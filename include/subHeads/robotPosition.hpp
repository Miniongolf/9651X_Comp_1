#include "main.h"

class RobotPosition {
    public:
        double x, y, angle;
        
        /**
         * Robot Position class constructor
         * \param x
         *        x coordinate
         * \param y
         *        y coordinate
         * \param angle
         *        heading
         */
        RobotPosition(double xIn, double yIn, double angleIn);
};