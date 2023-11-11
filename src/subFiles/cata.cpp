#include "main.h"

Cata::Cata() {}

void Cata::runContinuous(int runtime) {
    cataMotors.move(127);
    if (runtime > 0) {
        pros::delay(runtime);
        cataMotors.move(0);
    }
}