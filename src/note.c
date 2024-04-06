#include "note.h"
#include <math.h>

float calculateFrequency(int noteNumber, int octave) {
    static const char notes[] = {'C', 'C#', 'D', 'D#', 'E', 'F', 'F#', 'G', 'G#', 'A', 'A#', 'B'}; 
    static const int intervalsFromA[] = {0, 2, 3, 5, 7, 8, 10, 11, 13, 14, 16, 17};

    // Handle pause
    if (noteNumber == 0) {
        return 0.0;
    }

    // Adjust note index for 1-based input
    int noteIndex = noteNumber - 1;

    // Ensure note is within valid range
    if (noteIndex < 0 || noteIndex >= 12) {
        return -1.0; // Indicate invalid note
    }

    // Ensure octave is valid
    if (octave < 0 || octave > 8) {
        return -1.0; // Indicate invalid octave
    }

    // Calculate semitone distance from A in the specified octave
    int semitonesFromA = intervalsFromA[noteIndex] + 12 * (octave - 4); 

    // Calculate the frequency
    return 55.0 * pow(2.0, semitonesFromA / 12.0); 
}