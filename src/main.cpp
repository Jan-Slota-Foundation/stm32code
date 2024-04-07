#include <Arduino.h>
#include "display.h"
#include "songs.h"
#include "note.h"

// pins
#define LED_2 10
#define LED_3 11
#define BUTTON_LED 12
#define SERIAL_LED 13
#define BUTTON_LEFT A1
#define BUTTON_MIDDLE A2
#define BUTTON_RIGHT A3

// led states
#define LED_ON LOW
#define LED_OFF HIGH

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

void setup_buttons() {
  pinMode(BUTTON_LEFT, INPUT);
  pinMode(BUTTON_MIDDLE, INPUT);
  pinMode(BUTTON_RIGHT, INPUT);
}

void setup_leds() {
  pinMode(LED_2, OUTPUT);
  digitalWrite(LED_2, LED_OFF);
  pinMode(LED_3, OUTPUT);
  digitalWrite(LED_3, LED_OFF);
  pinMode(BUTTON_LED, OUTPUT);
  digitalWrite(BUTTON_LED, LED_OFF);
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

  digitalWrite(SERIAL_LED, LED_ON); 
  Serial.begin(9600);
}

void loop() {
  if (!digitalRead(BUTTON_LEFT)) {
      Song s;
      Note currentNote;
      int songIndex = 0;
      digitalWrite(LED_2, LED_ON);

      while (currentNote.note != TERMINATE) {
        while (Serial.available() < 1) {delay(100);}

        char *buffer = new char[3];
        currentNote.note = Serial.readBytes(buffer, 3);
        currentNote.note = buffer[0] - '0';

        currentNote.octave = buffer[1] - '0';

        currentNote.duration = buffer[2] - '0';
 
        s.melody[songIndex] = currentNote;
        songIndex++;
      }

      while (Serial.available() < 1) {}

      // s.tempo = Serial.parseInt();
      // Serial.println(s.tempo);
      s.tempo = 128;
      digitalWrite(LED_3, LED_OFF);
      digitalWrite(LED_2, LED_OFF);
      playSong(s);
      delay(1000);
      noTone(BUZZER_PIN);
      digitalWrite(BUTTON_LED, LED_OFF);
  }
}