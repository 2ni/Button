/**
 * Simple push button library to distinguis between
 * long and short pushes
 *
 */

#include <Arduino.h>

#include <Button.h>

void buttonPressed(Button::pushType type) {
  if (type == Button::SHORT_PUSH) {
    Serial.println("short push");
  } else if (type == Button::LONG_PUSH) {
    Serial.println("long push");
  }
}

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
