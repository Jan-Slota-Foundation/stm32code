#ifndef SONG_H
#define SONG_H

#include "note.h"
#include <Arduino.h>

#define BUZZER_PIN 3

typedef struct Song {
    Note melody[MAX_NOTES];
    int tempo;
} Song;

void playSong(const Song &song);
double calculateFrequency(int noteNumber, int octave);

#endif