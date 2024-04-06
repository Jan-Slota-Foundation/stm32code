#ifndef SONGLIST_H
#define SONGLIST_H

#include "note.h"
#include "song.h"

//   // Super Mario Bros. Theme
//   NOTE_E4,-8, NOTE_E4,8, NO_NOTE,8, NOTE_E4,-8, NOTE_REST,8, NOTE_C4,-8, NOTE_E4,8, NOTE_G4,-4, NOTE_REST,4, 
//   NOTE_G3,-4, NOTE_REST,4, NOTE_C4,-8, NOTE_REST,2, NOTE_G3,-8, NOTE_REST,2, NOTE_E3,-8, NOTE_REST,8, 
//   NOTE_A3,-8, NOTE_B3,8, NOTE_AS3,8, NOTE_A3,16, NOTE_G3,-8, NOTE_E4,-8, NOTE_G4,-4, NOTE_A4,8, NOTE_F4,8, 
//   NOTE_G4,16, NOTE_E4,-8, NOTE_C4,-8, NOTE_D4,8, NOTE_B3,-4, NOTE_REST,4, NOTE_C4,-8, NOTE_REST,2, NOTE_G3,-8, 
//   NOTE_REST,2, NOTE_E3,-8

// Mario Theme Song (Partial - add more notes)
const Song marioTheme = {
   {
        { 3, 300 }, { 1, 150 }, { 3, 300 }, { 1, 100 },  { 0, 100 }, { 3, 150 }, { 3, 150 }, { 0, 100},
        { 3, 300 }, { 5, 100 }, { 6, 100 }, { 7, 100 }, { 8, 100 }, { 9, 400 }, { 7, 100},
        { 5, 200 }, { 3, 300 }, { 1, 150 }, { 3, 300 }, { 1, 100 },  { 0, 100 }, { 3, 150 }, { 3, 150 }, { 0, 100},
        { 3, 300 }, { 0, 500 }, 
        { 1, 150}, { 2, 150}, { 3, 200}, { 2, 100 },  { 1, 100 }, { 0, 200 },  { 7,100 },  
        { 6, 100}, { 5, 500}, {0, 100},
        { -1, 0 } // End of song marker
   }, 
   120 // Tempo in BPM
};

#endif