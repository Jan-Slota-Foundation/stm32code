#include "single_note.h"

Note note = {4, 1, 0};

void addNote(int i) {
    if ((note.note + i) % 13 == 0 && i > 0) {
        note.note = 1;
        note.octave++;
    } else if ((note.note + i) == 0 && i < 0) {
        note.note = 12;
        note.octave--;
    }else {
        note.note += i;
    }
    calculateFrequency(note.note, note.octave);
    Serial.printf("Note: %d, Octave: %d\n", note.note, note.octave);
}

void handle_single_note(int r1, int r2, State *state)
{   
    if (r1 == 1) {
        state->playing = !state->playing;
        Serial.printf("Playing: %d\n", state->playing);
    }

    if (r2 == 1) {
        addNote(1);
    } else if (r2 == 2) {
        addNote(-1);
    }

    if (state->playing)
    {
        tone(BUZZER_PIN, calculateFrequency(note.note, note.octave));
    } else {
        noTone(BUZZER_PIN);
    }
}

void finish_single_note_state() {
    noTone(BUZZER_PIN);
}