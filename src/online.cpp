#include "online.h"
#include <Arduino.h>

// 0 means notes, 1 means tempo
int reading_state = 0;
int found_terminate = -1;

int songIndex = 0;

Song s;
Note currentNote;

void handle_online(int r1, int r2, State *state) {
    char *buffer = new char[3];
    if (found_terminate == -1) {
        Serial.println("Enter notes:");
        digitalWrite(LED_2, LED_ON);
        s = Song();
        songIndex = 0;
        currentNote = Note();
        found_terminate = 0;
    } else if (found_terminate == 0) {
        if (Serial.available() > 1) {
            currentNote.note = Serial.readBytes(buffer, 3);
            currentNote.note = buffer[0] - '0';

            currentNote.octave = buffer[1] - '0';

            currentNote.duration = buffer[2] - '0';

            s.melody[songIndex] = currentNote;
            songIndex++;
            if (currentNote.note == TERMINATE) {
                found_terminate = 1;
            }
        }
    } else if (found_terminate == 1) {
        if (Serial.available() > 1) {
            s.tempo = Serial.readBytes(buffer, 3);
            s.tempo = buffer[0] - '0';
            s.tempo = s.tempo * 2.5;
            //s.tempo = 128;
            digitalWrite(LED_3, LED_OFF);
            digitalWrite(LED_2, LED_OFF);
            playSong(s);
            delay(1000);
            noTone(BUZZER_PIN);
            Serial.println("Song played");
            found_terminate = -1;
        }
    }
    delete buffer;
}

void finish_online_state() {
    // Do nothing
}