#ifndef SONGLIST_H
#define SONGLIST_H

#include "song.h"

#define NUMBER_OF_SONGS 3

// koniec -1
// pauza 0
//   A 1
//   A# 2
//   B 3
//   C 4
//   C# 5
//   D 6
//   D# 7
//   E 8
//   F 9
//   F# 10
//   G 11
//   G# 12

/*
C4 (1) - C4 (1/2) - G4 (1/2) - A3 (1) - C4 (1) - C4 (1/2) - G4 (1/2) - A3 (1)
C4 (1) - C4 (1/2) - G4 (1/2) - A3 (1) - C4 (1) - C4 (1/2) - G4 (1/2) - A3 (1)
G4 (1) - G4 (1/2) - F4 (1/2) - E4 (1) - G4 (1) - G4 (1/2) - F4 (1/2) - E4 (1)
E4 (1) - E4 (1/2) - D4 (1/2) - C4 (1) - E4 (1) - E4 (1/2) - D4 (1/2) - C4 (1)
*/


const Song marioTheme = {
    {
        // {note, octave(starting at 1 not 4), duration}
        {4, 1, 3},
        {4, 1, 2},
        {11, 4, 2},
        {9, 3, 3},
        {4, 1, 3},
        {4, 1, 2},
        {11, 4, 2},
        {9, 3, 3},
        {4, 1, 3},
        {4, 1, 2},
        {11, 4, 2},
        {9, 3, 3},
        {4, 1, 3},
        {4, 1, 2},
        {11, 4, 2},
        {9, 3, 3},
        {11, 4, 3},
        {11, 4, 2},
        {10, 4, 2},
        {8, 4, 3},
        {11, 4, 3},
        {11, 4, 2},
        {10, 4, 2},
        {8, 4, 3},
        {8, 4, 3},
        {8, 4, 2},
        {7, 4, 2},
        {4, 1, 3},
        {8, 4, 3},
        {8, 4, 2},
        {7, 4, 2},
        {4, 1, 3},
        // ... add more notes for the rest of the melody
    },
    400 // A moderate tempo
};


const Song BadApple = {
    {

{4, 3, 1}, // MIDI Note: 48 Velocity: 127
{4, 3, 1}, // MIDI Note: 48 Velocity: 0
{5, 3, 1}, // MIDI Note: 49 Velocity: 127
{5, 3, 1}, // MIDI Note: 49 Velocity: 0
{6, 3, 1}, // MIDI Note: 50 Velocity: 127
{6, 3, 1}, // MIDI Note: 50 Velocity: 0
{7, 3, 1}, // MIDI Note: 51 Velocity: 127
{7, 3, 1}, // MIDI Note: 51 Velocity: 0
{8, 3, 1}, // MIDI Note: 52 Velocity: 127
{8, 3, 1}, // MIDI Note: 52 Velocity: 0
{9, 3, 1}, // MIDI Note: 53 Velocity: 127
{9, 3, 1}, // MIDI Note: 53 Velocity: 0
{10, 3, 1}, // MIDI Note: 54 Velocity: 127
{10, 3, 1}, // MIDI Note: 54 Velocity: 0
{11, 3, 1}, // MIDI Note: 55 Velocity: 127
{11, 3, 1}, // MIDI Note: 55 Velocity: 0
{12, 3, 1}, // MIDI Note: 56 Velocity: 127
{12, 3, 1}, // MIDI Note: 56 Velocity: 0
{1, 3, 1}, // MIDI Note: 57 Velocity: 127
{1, 3, 1}, // MIDI Note: 57 Velocity: 0
{2, 3, 1}, // MIDI Note: 58 Velocity: 127
{2, 3, 1}, // MIDI Note: 58 Velocity: 0
{3, 3, 1}, // MIDI Note: 59 Velocity: 127
{3, 3, 1}, // MIDI Note: 59 Velocity: 0


        {TERMINATE, 0, 1}
    },
    600 // 125 * 2
};


const Song happyBirthday = {
    {
        {4, 4, 3},
        {4, 4, 3}, 
        {4, 4, 3}, 
        {6, 4, 3}, 
        {4, 4, 3},
        {9, 4, 3},
        {8, 4, 3},{0, 0, 4},

        {4, 4, 3}, 
        {4, 4, 3}, 
        {6, 4, 3}, 
        {4, 4, 3},
        {11, 4, 3},
        {9, 4, 3},{0, 0, 4},
        
        {4, 4, 3}, 
        {4, 4, 3}, 
        {4, 5, 3}, 
        {1, 4, 3}, 
        {9, 4, 3},
        {9, 4, 3},
        {8, 4, 3},
        {6, 4, 3},{0, 0, 4},

        {2, 4, 3}, 
        {2, 4, 3}, 
        {1, 4, 3}, 
        {9, 4, 3}, 
        {11, 4, 3},
        {9, 4, 3},
        {TERMINATE, 0, 1}
    },
    600 // 125 * 2
};


const Song static_songs[] = {
    happyBirthday,
    marioTheme,
    BadApple
};

#endif
