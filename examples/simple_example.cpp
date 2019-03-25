/**
 * Simple push button library to distinguish between
 * long and short pushes
 *
 */

#include <Arduino.h>
#include <Button.h>

#define BUTTON 39 // any GPIO pin
#define LED 17    // GPIO where a LED is connected to

/*
 * Callback function when a push is detected
 * <type> can be SHORT_PUSH or LONG_PUSH
 *
 */
void buttonPressed(Button::pushType type) {
  if (type == Button::SHORT_PUSH) {
    Serial.println("short push");
  } else if (type == Button::LONG_PUSH) {
    Serial.println("long push");
  }
}

Button button = Button(BUTTON, LED, buttonPressed);

void setup() {
  // uart
  Serial.begin(115200);
  Serial.setTimeout(2000);
  while(!Serial) { }

  Serial.println("Hello there.");

  button.setup();
}

void loop() {
  button.read();
}
