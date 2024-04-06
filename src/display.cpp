#include <Arduino.h>


// Pin definitions
const int SER_Pin = 8; // Serial Input
const int CLK_Pin = 7; // Clock Input
const int RCK_Pin = 4; // Register Clock (Latch)

const uint8_t numbers[] = {0xC0,0xF9,0xA4,0xB0,0x99,0x92,0x82,0xF8,0x80,0x90};

void displayNumber(int number) {
    /*int count = 0;
    int digits[4]; 
    
    if (number == 0) {
        count = 1;
        digits[0] = 0;
    } else {
        int tempNumber = number;
        while (tempNumber != 0) {
            tempNumber /= 10;
            ++count;
        }

        for (int i = count - 1; i >= 0; --i) {
            digits[i] = number % 10;
            number /= 10;
        }
    }

    for (int i = 0; i < 4; ++i) {
          byte digitPattern = 1 << (i+1 - 1); // Select the correct digit
          shiftOut(~numbers[digits[i]]); // Send segment pattern (invert for common anode)
          shiftOut(digitPattern); // Select digit (invert for common anode)
          latch(); // Update display
    } 
    */


    digitalWrite(RCK_Pin,LOW);                                
    shiftOut(SER_Pin, CLK_Pin, MSBFIRST, numbers[number]);   
    shiftOut(SER_Pin, CLK_Pin, MSBFIRST, 0xF1);    
    digitalWrite(RCK_Pin,HIGH); 

  }




void setup() {
  // Initialize pins
  pinMode(SER_Pin, OUTPUT);
  pinMode(CLK_Pin, OUTPUT);
  pinMode(RCK_Pin, OUTPUT);
  displayNumber(1);
               
}





void loop() {
 

      
}
