#include "display.h"
#include "songs.h"
#include "note.h"
#include "runner.h"
#include "main.h"
#include "button.h"


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
Button b;

void setup_buttons() {
  b = init_button(BUTTON_LEFT);
}

void setup_leds() {
  pinMode(LED_1, OUTPUT);
  digitalWrite(LED_1, LED_OFF);
  pinMode(LED_2, OUTPUT);
  digitalWrite(LED_2, LED_OFF);
  pinMode(LED_3, OUTPUT);
  digitalWrite(LED_3, LED_OFF);
}

void setup_buzzer() {
  digitalWrite(BUZZER_PIN, HIGH);   // first! else short sound
  pinMode(BUZZER_PIN, OUTPUT);
}

void setup() {
  pinMode(SERIAL_LED, OUTPUT);
  digitalWrite(SERIAL_LED, LED_OFF);

  setup_buttons();
  setup_leds();
  setup_buzzer();
  setupDisplay();

  setup_runner();

  //digitalWrite(SERIAL_LED, LED_ON); 
  Serial.begin(9600);
}

void loop() {
  int u = update_button(&b);
  run(u);
}