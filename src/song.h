#ifndef SONG_H
#define SONG_H

#include "note.h"

typedef struct Song {
    Note melody[MAX_NOTES];
    int tempo;
} Song;

#endif