#include <Arduino.h>

// pins
#define BUTTON_LED 12
#define SERIAL_LED 13
#define BUTTON_LEFT A1
#define BUTTON_MIDDLE A2
#define BUTTON_RIGHT A3

// led states
#define LED_ON LOW
#define LED_OFF HIGH

/*
  LEDS ARE CATODE CONNECTED
*/

/*
log for printing/reading from serial:
// get 2 numbers to print from serail
  int x, y;
  Serial.println("Enter 2 numbers:");
  while (Serial.available() < 2) {
    delay(100);
  }
  x = Serial.parseInt();
  y = Serial.parseInt();
  Serial.print("Sum of ");
  Serial.print(x);
  Serial.print(" and ");
  Serial.print(y);
  Serial.print(" is ");
  Serial.println(myFunction(x, y));

// log for reading buttons:
while (digitalRead(BUTTON_LEFT));     // wait until S1 (low active)
  Serial.printf("%i\n", digitalRead(BUTTON_LEFT));
  delay(1000);
  if (!digitalRead(BUTTON_LEFT)) {
    digitalWrite(BUTTON_LED, LED_ON);
    delay(1000);
  } else {
    digitalWrite(BUTTON_LED, LED_OFF);
    delay(1000);
  }
*/

// put function declarations here:
int myFunction(int, int);

void setup() {
  pinMode(SERIAL_LED, OUTPUT);
  digitalWrite(SERIAL_LED, LED_OFF);

  pinMode(BUTTON_LED, OUTPUT);

  pinMode(BUTTON_LEFT, INPUT);
  // pinMode(BUTTON_MIDDLE, INPUT_PULLDOWN);
  // pinMode(BUTTON_RIGHT, INPUT_PULLDOWN);

  digitalWrite(BUTTON_LED, LED_OFF);

  Serial.begin(9600);
  digitalWrite(SERIAL_LED, LED_ON);
}

void loop() {
  // put your main code here, to run repeatedly:

}

// put function definitions here:
int myFunction(int x, int y) {
  return x + y;
}