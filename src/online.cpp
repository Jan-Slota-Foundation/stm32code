#include "online.h"
#include <Arduino.h>

void handle_online(int r1, int r2, State *state) {
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
}

void finish_online_state() {
    // Do nothing
}