#pragma once
#include "main.h"

class PID {
    private:
        double kP, kI, kD;
        double integral = 0; // integral sum
        double maxSumIntegral = 0.5; // max integral sum, half full output(1.0)
        double integralRange = 0; // in the error range start the integral
        double derivative = 0, lastDerivative = 0;

        double filterAlpha = 1.0;  // filter factor, filterFac * current + (1- filterFac) * last

        bool shouldResetOnCross = true;  // when error changes sign, reset integral

        // normalize output to [-1, 1] for compatability with chassis class
        double maxOutput = 1.0, minOutput = -1.0;

        double target = 0;
        double newReading = 0;
        double lastReading = 0;
        double error = 0;
        double lastError = 0;

    public:
        /**
         * PID class constructor
         * \param kP
         *        proportional constant multiplier
         * \param kI
         *        integral constant multiplier
         * \param kD
         *        derivative constant multiplier
         */
        PID(double kPin, double kIin, double kDin);

        /**
         * Set new PID constants
         * \param kP
         *        proportional constant multiplier
         * \param kI
         *        integral constant multiplier
         * \param kD
         *        derivative constant multiplier
         * \returns `None`
         */
        void setPID(double kPin, double kIin, double kDin);

        /**
         * Set new target distance
         * \param target
         *        new target distance
         * \returns `None`
         */
        void setTarget(double targetIn);

        // void setReading(double reading);
        // void setOutputRange(double min, double max);

        /**
         * Calculate instantaneous PID controller output based on error
         * \param error
         *        Error between target and current value
         * \returns chassis motor powers [-1, 1]
         */
        double calculate(double errorIn);

        /**
         * Calculate instantaneous proportional controller values based on error
         * \param error
         *        Error between target and current value
         * \returns chassis motor powers [-1, 1]
         */
        double calculateLinearKP(double errorIn);
};