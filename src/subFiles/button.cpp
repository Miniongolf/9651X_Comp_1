#include "main.h"

// Default constructor
Button::Button() {}

// Sets the button state of pressed, held, and released
void Button::setStatus(bool isPressed) {
    currState = isPressed;
    
    // Rising edge detection
    if (!prevState && currState) {
        pressed = true;
        held = true;
        released = false;
    }
    
    // Sustained
    else if (prevState && currState) {
        pressed = false;
        held = true;
        released = false;
    }
    
    // Falling edge detection
    else if (prevState && !currState) {
        pressed = false;
        held = false;
        released = true;
    }
    
    // Released
    else {
        pressed = false;
        held = false;
        released = false;
    }

    // Update for next iteration
    prevState = currState;
}

