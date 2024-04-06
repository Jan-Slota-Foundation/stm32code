#include <Arduino.h>

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

#define NOTE_B0 31
#define NOTE_C1 33
#define NOTE_CS1 35
#define NOTE_D1 37
#define NOTE_DS1 39
#define NOTE_E1 41
#define NOTE_F1 44
#define NOTE_FS1 46
#define NOTE_G1 49
#define NOTE_GS1 52
#define NOTE_A1 55
#define NOTE_AS1 58
#define NOTE_B1 62
#define NOTE_C2 65
#define NOTE_CS2 69
#define NOTE_D2 73
#define NOTE_DS2 78
#define NOTE_E2 82
#define NOTE_F2 87
#define NOTE_FS2 93
#define NOTE_G2 98
#define NOTE_GS2 104
#define NOTE_A2 110
#define NOTE_AS2 117
#define NOTE_B2 123
#define NOTE_C3 131
#define NOTE_CS3 139
#define NOTE_D3 147
#define NOTE_DS3 156
#define NOTE_E3 165
#define NOTE_F3 175
#define NOTE_FS3 185
#define NOTE_G3 196
#define NOTE_GS3 208
#define NOTE_A3 220
#define NOTE_AS3 233
#define NOTE_B3 247
#define NOTE_C4 262
#define NOTE_CS4 277
#define NOTE_D4 294
#define NOTE_DS4 311
#define NOTE_E4 330
#define NOTE_F4 349
#define NOTE_FS4 370
#define NOTE_G4 392
#define NOTE_GS4 415
#define NOTE_A4 440
#define NOTE_AS4 466
#define NOTE_B4 494
#define NOTE_C5 523
#define NOTE_CS5 554
#define NOTE_D5 587
#define NOTE_DS5 622
#define NOTE_E5 659
#define NOTE_F5 698
#define NOTE_FS5 740
#define NOTE_G5 784
#define NOTE_GS5 831
#define NOTE_A5 880
#define NOTE_AS5 932
#define NOTE_B5 988
#define NOTE_C6 1047
#define NOTE_CS6 1109
#define NOTE_D6 1175
#define NOTE_DS6 1245
#define NOTE_E6 1319
#define NOTE_F6 1397
#define NOTE_FS6 1480
#define NOTE_G6 1568
#define NOTE_GS6 1661
#define NOTE_A6 1760
#define NOTE_AS6 1865
#define NOTE_B6 1976
#define NOTE_C7 2093
#define NOTE_CS7 2217
#define NOTE_D7 2349
#define NOTE_DS7 2489
#define NOTE_E7 2637
#define NOTE_F7 2794
#define NOTE_FS7 2960
#define NOTE_G7 3136
#define NOTE_GS7 3322
#define NOTE_A7 3520
#define NOTE_AS7 3729
#define NOTE_B7 3951
#define NOTE_C8 4186
#define NOTE_CS8 4435
#define NOTE_D8 4699
#define NOTE_DS8 4978
#define NOTE_REST 0
#define NO_NOTE 0

// change this to make the song slower or faster
int tempo = 144;

// change this to whichever pin you want to use
int buzzer = BUZZER_PIN;

// notes of the moledy followed by the duration.
int melody[] = {

  // Super Mario Bros. Theme
  NOTE_E4,-8, NOTE_E4,8, NO_NOTE,8, NOTE_E4,-8, NOTE_REST,8, NOTE_C4,-8, NOTE_E4,8, NOTE_G4,-4, NOTE_REST,4, 
  NOTE_G3,-4, NOTE_REST,4, NOTE_C4,-8, NOTE_REST,2, NOTE_G3,-8, NOTE_REST,2, NOTE_E3,-8, NOTE_REST,8, 
  NOTE_A3,-8, NOTE_B3,8, NOTE_AS3,8, NOTE_A3,16, NOTE_G3,-8, NOTE_E4,-8, NOTE_G4,-4, NOTE_A4,8, NOTE_F4,8, 
  NOTE_G4,16, NOTE_E4,-8, NOTE_C4,-8, NOTE_D4,8, NOTE_B3,-4, NOTE_REST,4, NOTE_C4,-8, NOTE_REST,2, NOTE_G3,-8, 
  NOTE_REST,2, NOTE_E3,-8
};

// sizeof gives the number of bytes, each int value is composed of two bytes (16 bits)
// there are two values per note (pitch and duration), so for each note there are four bytes
int notes = sizeof(melody) / sizeof(melody[0]) / 2;

// this calculates the duration of a whole note in ms
int wholenote = (60000 * 4) / tempo;

int divider = 0, noteDuration = 0;


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
  digitalWrite(BUTTON_LED, LED_OFF);

  pinMode(BUTTON_LEFT, INPUT);
  pinMode(BUTTON_MIDDLE, INPUT_PULLDOWN);
  pinMode(BUTTON_RIGHT, INPUT_PULLDOWN);

  digitalWrite(BUZZER_PIN, HIGH);   // first! else short sound
  pinMode(BUZZER_PIN, OUTPUT);

  Serial.begin(9600);
  digitalWrite(SERIAL_LED, LED_ON);
}

void loop() {
  // put your main code here, to run repeatedly:
  // put your main code here, to run repeatedly:
  // tone(BUZZER_PIN, 261); // Do
  // delay(500);
  // tone(BUZZER_PIN, 294); // Re
  // delay(500);
  // tone(BUZZER_PIN, 330); // Mi
  // delay(500);
  // tone(BUZZER_PIN, 349); // Fa
  // delay(500);
  // tone(BUZZER_PIN, 392); // So
  // delay(500);
  // tone(BUZZER_PIN, 440); // La
  // delay(500);
  // tone(BUZZER_PIN, 494); // Si
  // delay(500);
  // tone(BUZZER_PIN, 523); // Do
  // delay(500);
  // noTone(BUZZER_PIN); // Stop playing the note
  // delay(1000); // Delay for 1 second

  //  for (int thisNote = 0; thisNote < notes * 2; thisNote = thisNote + 2) {

  //   // calculates the duration of each note
  //   divider = melody[thisNote + 1];
  //   if (divider > 0) {
  //     // regular note, just proceed
  //     noteDuration = (wholenote) / divider;
  //   } else if (divider < 0) {
  //     // dotted notes are represented with negative durations!!
  //     noteDuration = (wholenote) / abs(divider);
  //     noteDuration *= 1.5; // increases the duration in half for dotted notes
  //   }

  //   // we only play the note for 90% of the duration, leaving 10% as a pause 
  //   tone(buzzer, melody[thisNote], noteDuration*0.9);

  //   // Wait for the specief duration before playing the next note.
  //   delay(noteDuration);

  //   // stop the waveform generation before the next note.
  //   noTone(buzzer);
  // }
  tone(BUZZER_PIN, 33, 500);
  //delay(2000);

}

// put function definitions here:
int myFunction(int x, int y) {
  return x + y;
}