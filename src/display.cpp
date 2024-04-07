#include "display.h"

const uint8_t numbers[] = {0xC0,0xF9,0xA4,0xB0,0x99,0x92,0x82,0xF8,0x80,0x90};

void displayNumber(int number) {
    digitalWrite(RCK,LOW);                                
    shiftOut(SER, CLK, MSBFIRST, numbers[number]);   
    shiftOut(SER, CLK, MSBFIRST, 0xF1);    
    digitalWrite(RCK,HIGH); 

}

void setupDisplay() {
  pinMode(SER, OUTPUT);
  pinMode(CLK, OUTPUT);
  pinMode(RCK, OUTPUT);
  displayNumber(1);
}
