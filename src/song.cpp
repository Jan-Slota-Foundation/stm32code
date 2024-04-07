#include "song.h"

void playSong(const Song &song) {
    // Calculate duration of a quarter note in milliseconds
    float quarterNoteDuration = 60000.0 / song.tempo; 
    float fullNoteDuration = quarterNoteDuration * 4;

    for (int i = 0; i < MAX_NOTES && song.melody[i].note != ('K' - '0'); i++) {
        double frequency = calculateFrequency(song.melody[i].note, song.melody[i].octave); 
        int noteDuration = quarterNoteDuration * song.melody[i].duration;

        tone(BUZZER_PIN, frequency, noteDuration);
        delay(noteDuration); // Rest is implied, no extra calculations needed
        noTone(BUZZER_PIN);
        delay(fullNoteDuration - noteDuration); // Rest is implied, no extra calculations needed
        delay(50);
    }
}

double calculateFrequency(int noteNumber, int octave) {
    // Handle pause
    if (noteNumber == 0) {
        return 0.0;
    }

    // Adjust note index for 1-based input
    noteNumber = noteNumber - 1;
    octave = octave - 1;
    if (noteNumber != 0 && noteNumber != 2) {
      octave -= 1;
    }
    // Ensure note is within valid range
    if (noteNumber < 0 || noteNumber >= 12) {
        return -1.0; // Indicate invalid note
    }

    // Ensure octave is valid
    if (octave < 0 || octave > 8) {
        return -1.0; // Indicate invalid octave
    }

    // Calculate the frequency
    double res =  55.00 * pow(2.0, (noteNumber + (12 * octave)) / 12.0); 
    // round here to 2 decimal places
    float b = round(res * 100.0) / 100.0;
    return b;
}