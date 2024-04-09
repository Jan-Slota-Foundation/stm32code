#ifndef BUTTON_DOUBLE_H
#define BUTTON_DOUBLE_H

#include <Arduino.h>

typedef enum  {
  IDLE,
  FIRST_PRESS,
  FIRST_RELEASE,
  SECOND_PRESS,
  SECOND_RELEASE
} ButtonState;

#define CLICK_DELAY 500 // Time (in milliseconds) to wait for a second click
#define DEBOUNCE_DELAY 50 // Time (in milliseconds) to debounce the button

typedef struct {
  int buttonPin = 0;

  int buttonState;

  unsigned long timePress = 0;
  unsigned long timePressLimit = 0;
  int clicks = 0;
} Button;

Button init_button(int pin);
int update_button(Button *button);

#endif