#include "save.h"
#include "display.h"
#include "fs.h"

int save_init = 0;
bool stuff_to_save = true;
unsigned long last_blink = 0;
int song_to_save = 0;

unsigned long last_save_not_change = 0;
int current_save_note = 0;

void handle_save(int r1, int r2, State *state)
{
    if (!save_init)
    {
        displayNumber(9);
        Serial.println("initializing save state");
        if (state->songIndex == 0)
        {
            stuff_to_save = false;
        }
        save_init = 1;
    } 

    if (stuff_to_save)
    {        displayNumber(song_to_save);

        if (r1 == 1)
        {
            song_to_save = (song_to_save + 1) % state->songIndex;
        }
        else if (r1 == 2)
        {
            song_to_save = (song_to_save - 1 + 5) % state->songIndex;
        }

        if (r2 == 1 || r2 == 2)
        {
            Serial.println("saving song");
            fs_write(state->songs[song_to_save]);
            finish_save_state();
            state->state = SINGLE_NOTE;
            return;
        }

        if (state->playing)
        {
            int quater = MS_IN_MINUTE / state->songs[song_to_save].tempo;
            int change = quater * state->songs[song_to_save].melody[current_save_note].duration;
            if (millis() - last_save_not_change > change + 50) {
            last_save_not_change = millis();
            current_save_note += 1;
            if (state->songs[song_to_save].melody[current_save_note].note == TERMINATE) {
                current_save_note = 0;
            }

            tone(BUZZER_PIN, calculateFrequency(state->songs[song_to_save].melody[current_save_note].note, 
            state->songs[song_to_save].melody[current_save_note].octave), 
            quater * state->songs[song_to_save].melody[current_save_note].duration);
            }
        }
    }
    else
    {
        // blink with all 3 leds
        if (millis() - last_blink > 1000)
        {
            last_blink = millis();
            digitalWrite(LED_1, !digitalRead(LED_1));
            digitalWrite(LED_2, !digitalRead(LED_2));
            digitalWrite(LED_3, !digitalRead(LED_3));
        }
    }
}

void finish_save_state()
{
    save_init = 0;
    stuff_to_save = true;
    last_blink = 0;
    song_to_save = 0;
    current_save_note = 0;
    noTone(BUZZER_PIN);
}
