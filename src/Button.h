/**
 * Library to handle long and short push buttons
 */

#ifndef button_h
#define button_h

#include <Arduino.h>

class Button {

public:
  typedef enum {
    NO_PUSH,
    PUSHING,
    LONG_PUSH,
    SHORT_PUSH,
  } pushType;

  Button(int iButton, void (*callback)(pushType type));
  Button(int iButton, int iLed);
  Button(int iButton, int iLed, void (*callback)(pushType type));

  void setCallback(void (*callback)(pushType type));
  void setup();
  void read();

private:
  pushType mode = NO_PUSH;
  int button = -1;
  int led = -1;
  unsigned long timer = 0;
  unsigned long timerLed = -1;
  void(*callback)(pushType type);
};
#endif
