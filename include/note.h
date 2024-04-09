#ifndef NOTES_H
#define NOTES_H

#define MAX_NOTES 100
#define MS_IN_MINUTE 60000
#define TERMINATE ('K' - '0')

typedef struct {
    short note;
    short octave;
    short duration;
} Note;

#endif