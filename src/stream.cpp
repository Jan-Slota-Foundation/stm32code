#include "stream.h"

int song_to_play = -1;
int init_stream = 0;
unsigned long last_stream_not_change = 0;
int current_stream_note = 0;

void handle_stream(int r1, int r2, State *state) {
    if (state->songIndex > 0 && init_stream == 0) {
        song_to_play = 0;
        init_stream = 1;
    }

    if (r1 == 1) {
        song_to_play = (song_to_play + 1) % state->songIndex;
    } else if (r1 == 2) {
        song_to_play = (song_to_play - 1 + 5) % state->songIndex;
    }

    if (state->playing)
    {
        int quater = MS_IN_MINUTE / state->songs[song_to_play].tempo;
        int change = quater * state->songs[song_to_play].melody[current_stream_note].duration;
        if (millis() - last_stream_not_change > change + 50) {
        last_stream_not_change = millis();
        current_stream_note += 1;
        if (state->songs[song_to_play].melody[current_stream_note].note == TERMINATE) {
            current_stream_note = 0;
        }

        tone(BUZZER_PIN, calculateFrequency(state->songs[song_to_play].melody[current_stream_note].note, 
        state->songs[song_to_play].melody[current_stream_note].octave), 
        quater * state->songs[song_to_play].melody[current_stream_note].duration);
        }
    }
}

void finish_stream_state() {
    song_to_play = -1;
    init_stream = 0;  
    last_stream_not_change = 0;
    current_stream_note = 0;
} 