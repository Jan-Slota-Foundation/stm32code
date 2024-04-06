#include <Arduino.h>

#define LED_PIN 13

// put function declarations here:
int myFunction(int, int);

void setup() {
  pinMode(LED_PIN, OUTPUT);
  digitalWrite(LED_PIN, HIGH);
  delay(1000);
  digitalWrite(LED_PIN, LOW);
  delay(1000);
  digitalWrite(LED_PIN, HIGH);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println(myFunction(2, 3));
  digitalWrite(LED_PIN, HIGH);
  delay(1000);
  Serial.println(myFunction(5, 7));
  digitalWrite(LED_PIN, LOW);
  delay(1000);

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
}

// put function definitions here:
int myFunction(int x, int y) {
  return x + y;
}