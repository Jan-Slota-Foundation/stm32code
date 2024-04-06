#include <Arduino.h>
#include "display.h"
#include "songs.h"

// pins
#define BUTTON_LED 12
#define SERIAL_LED 13
#define BUTTON_LEFT A1
#define BUTTON_MIDDLE A2
#define BUTTON_RIGHT A3
#define BUZZER_PIN 3

// led states
#define LED_ON LOW
#define LED_OFF HIGH

/*
  notes:
  A
  A#
  B
  C
  C#
  D
  D#
  E
  F
  F#
  G
  G#
*/

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
void playSong(const Song &song);

double calculateFrequency(int noteNumber, int octave) {
    // Handle pause
    if (noteNumber == 0) {
        return 0.0;
    }

    // Adjust note index for 1-based input
    noteNumber = noteNumber - 1;
    octave = octave - 1;

    // Ensure note is within valid range
    if (noteNumber < 0 || noteNumber >= 12) {
        return -1.0; // Indicate invalid note
    }

    // Ensure octave is valid
    if (octave < 0 || octave > 8) {
        return -1.0; // Indicate invalid octave
    }

    // Calculate the frequency
    double res =  55.00 * pow(2.0, (noteNumber + (12 * octave)) / 12.0); 
    // round here to 2 decimal places
    float value = (int)(res * 100 + .5);
    return (float)value / 100;
}

void setup() {
  pinMode(SERIAL_LED, OUTPUT);
  digitalWrite(SERIAL_LED, LED_OFF);

  pinMode(BUTTON_LED, OUTPUT);
  digitalWrite(BUTTON_LED, LED_OFF);

  pinMode(BUTTON_LEFT, INPUT);
  pinMode(BUTTON_MIDDLE, INPUT_PULLDOWN);
  pinMode(BUTTON_RIGHT, INPUT_PULLDOWN);

  digitalWrite(BUZZER_PIN, HIGH);   // first! else short sound
  pinMode(BUZZER_PIN, OUTPUT);

  setupDisplay();

  Serial.begin(9600);
  digitalWrite(SERIAL_LED, LED_ON);
}

void loop() {
  if (!digitalRead(BUTTON_LEFT)) {
    playSong(marioTheme);
    delay(5000);
  }
}


void playSong(const Song &song) {
    // Calculate duration of a quarter note in milliseconds
    float quarterNoteDuration = 60000.0 / song.tempo; 
    float fullNoteDuration = quarterNoteDuration * 4;

    for (int i = 0; i < MAX_NOTES && song.melody[i].note != -1; i++) {
        double frequency = calculateFrequency(song.melody[i].note, song.melody[i].octave); 
        int noteDuration = quarterNoteDuration * song.melody[i].duration;

        tone(BUZZER_PIN, frequency, noteDuration);
        delay(noteDuration); // Rest is implied, no extra calculations needed
        noTone(BUZZER_PIN);
        delay(fullNoteDuration - noteDuration); // Rest is implied, no extra calculations needed
    }
}