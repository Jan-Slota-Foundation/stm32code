#ifndef RUNNER_H
#define RUNNER_H

#include "song.h"

typedef enum {
    SINGLE_NOTE,
    SCALE,
    COMPLEX_RECORD,
    WRITE_PLAY,
    STREAM,
    SAVE,
    LOAD,
    NONE
} RunnerStates;

typedef struct {
    RunnerStates state = SINGLE_NOTE;
    Song songs[5];
    bool playing;
    RunnerStates lastState = NONE;
    int songIndex = 0;
} State;

void setup_runner();

void run(int change);

#endif