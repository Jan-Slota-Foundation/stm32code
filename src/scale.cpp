#include "scale.h"
#include <Arduino.h>

Note notes[] = {
    {4, 3, 0},
    {6, 3, 0},
    {8, 3, 0},
    {9, 3, 0},
    {11, 3, 0},
    {1, 4, 0},
    {3, 4, 0},
};

int current_note = -1;
int direction = 1;

unsigned long last_note_change = 0;

void handle_scale(int r1, int r2, State *state) {
    if (r1 == 1) {
        state->playing = !state->playing;
        Serial.printf("Playing: %d\n", state->playing);
    }

    if (r2 == 1) {
        direction = 1;
    } else if (r2 == 2) {
        direction = -1;
    }

    if (state->playing)
    {
        if (millis() - last_note_change > 1000) {
            last_note_change = millis();
            current_note += direction;
            if (current_note >= 7) {
                current_note = 0;
            } else if (current_note < 0) {
                current_note = 7;
            }
            Serial.printf("Note: %d, Octave: %d\n", notes[current_note].note, notes[current_note].octave);
            tone(BUZZER_PIN, calculateFrequency(notes[current_note].note, notes[current_note].octave), 900);
        }
    } else {
        noTone(BUZZER_PIN);
    }
}

void finish_scale_state() {
    noTone(BUZZER_PIN);
}