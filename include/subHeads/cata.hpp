#include "main.h"

class Cata {
    public:
        Cata();

        /**
         * Runs the catapult motors at max power until released
         * \param runtime (optional)
         *        time to run the motor for
         *        
         * \returns none
         * \note Runtime is blocking
         */
        void runContinuous(int runtime=0);

        /**
         * Stops the catapult motors
         * \param None
         */
        void stop();
};