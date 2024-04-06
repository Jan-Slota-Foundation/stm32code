#ifndef DISPLAY_H
#define DISPLAY_H

#include <Arduino.h>

#define SER 8 // Serial Input
#define CLK 7 // Clock Input
#define RCK 4 // Register Clock (Latch)

void setupDisplay();
void displayNumber(int number);

#endif