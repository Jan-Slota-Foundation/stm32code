#include "complex.h"
#include <Arduino.h>
#include "songs.h"
#include "display.h"

int current_complex_song = 2;
int current_complex_note = 0;

unsigned long last_complex_note_change = 0;
int quater = 0;

void handle_complex(int r1, int r2, State *state) {
  displayNumber(current_complex_song);
  if (r1 == 1) {
      state->playing = !state->playing;
      Serial.printf("Playing: %d\n", current_complex_song);
  }

  if (r2 == 1) {
    current_complex_song -= (current_complex_song == 0) ? 0 : 1;
    current_complex_note = 0;
  } else if (r2 == 2) {
    current_complex_song += (current_complex_song == NUMBER_OF_SONGS) ? 0 : 1;
    current_complex_note = 0;
  }

  if (state->playing)
  {
    int quater = MS_IN_MINUTE / static_songs[current_complex_song].tempo;
    int change = quater * static_songs[current_complex_song].melody[current_complex_note].duration;
    if (millis() - last_complex_note_change > change + 50) {
      last_complex_note_change = millis();
      current_complex_note += 1;
      if (static_songs[current_complex_song].melody[current_complex_note].note == TERMINATE) {
        current_complex_note = 0;
      }

      tone(BUZZER_PIN, calculateFrequency(static_songs[current_complex_song].melody[current_complex_note].note, 
      static_songs[current_complex_song].melody[current_complex_note].octave), 
      quater * static_songs[current_complex_song].melody[current_complex_note].duration);
    }
  } else {
    noTone(BUZZER_PIN);
  }

}

void finish_complex_state() {
  // Do nothing
}