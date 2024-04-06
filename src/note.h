#ifndef NOTES_H
#define NOTES_H

#define MAX_NOTES 100
#define MS_IN_MINUTE 60000

typedef struct {
    short note;
    short octave;
    short duration;
} Note;


//float calculateFrequency(int noteNumber, int octave);


#endif