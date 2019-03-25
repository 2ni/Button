/**
 * Library to handle long and short push buttons
 * w/o timers
 *
 */

#include "Button.h"
#include "base_functions.h"

/*
Button::Button(int iButton, void (*iCallback)(void)) {
  button = iButton;
  callback = iCallback;
}
*/

Button::Button(int iButton, int iLed, void (*iCallback)(pushType type)) {
  button = iButton;
  led = iLed;
  callback = iCallback;
}

void Button::setCallback(void (*iCallback)(pushType type)) {
  callback = iCallback;
}

void Button::setup() {
  if (led != -1) {
    pinMode(led, OUTPUT);
  }
  pinMode(button, INPUT);
}

void Button::read() {
  // turn off led if necessary
  if (led && timerLed != -1 and millis()-timerLed > 100) {
    digitalWrite(led, 0);
    timerLed = -1;
  }

  // button is initially pressed
  int isButtonPressed = digitalRead(button);
  if (mode == NO_PUSH && isButtonPressed) {
    timer = millis(); // save timer for timeout long push
    mode = PUSHING;
    if (led) {
      digitalWrite(led, 1);
      timerLed = millis();
    }
  } else if (mode == PUSHING && !isButtonPressed) {
    // button released (short press)
    mode = NO_PUSH;
    callback(SHORT_PUSH);
  } else if (mode == PUSHING && millis() - timer > 200) {
    // button still pressed  (long press)
    mode = LONG_PUSH;
    callback(LONG_PUSH);
  } else if (mode == LONG_PUSH && !isButtonPressed) {
    // button is released
    mode = NO_PUSH;
  }
}
