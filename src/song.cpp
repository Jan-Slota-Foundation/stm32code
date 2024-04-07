#include "song.h"

void playSong(const Song &song) {
    // Calculate duration of a quarter note in milliseconds
    float quarterNoteDuration = 60000.0 / song.tempo; 
    float fullNoteDuration = quarterNoteDuration * 4;

    for (int i = 0; i < MAX_NOTES && song.melody[i].note != TERMINATE; i++) {
        double frequency = calculateFrequency(song.melody[i].note, song.melody[i].octave); 
        int noteDuration = quarterNoteDuration * song.melody[i].duration;

        tone(BUZZER_PIN, frequency, noteDuration);
        delay(noteDuration); // Rest is implied, no extra calculations needed
        noTone(BUZZER_PIN);
        delay(fullNoteDuration - noteDuration); // Rest is implied, no extra calculations needed
        delay(50);
    }
}

const float notes[8][12] = {
    // A      A#       B        C        C#       D        D#       E        F        F#       G        G#
    {27.50,   29.14,   30.8,    16.35,   17.32,   18.35,   19.45,   20.60,   21.83,   23.12,   24.50,   25.96},
    {55.00,   58.27,   61.47,   32.70,   34.65,   36.71,   38.89,   41.20,   43.65,   46.25,   49.00,   51.91},
    {110.00,  116.54,  123.47,  65.41,   69.30,   73.42,   77.78,   82.41,   87.31,   92.50,   98.00,   103.83},
    {220.00,  233.08,  246.94,  130.81,  138.59,  146.83,  155.56,  164.81,  174.61,  185.00,  196.00,  207.65},
    {440.00,  466.16,  493.88,  261.63,  277.18,  293.66,  311.13,  329.63,  349.23,  369.99,  392.00,  415.30},
    {880.00 , 932.33,  987.77,  523.25,  554.37,  587.33,  622.25,  659.26,  698.46,  739.99,  783.99,  830.61},
    {1760.00, 1864.66, 1975.53, 1046.50, 1108.73, 1174.66, 1244.51, 1318.51, 1396.91, 1479.98, 1567.98, 1661.22},
    {3520.00, 3729.31, 3951.07, 2093.00, 2217.46, 2349.32, 2489.02, 2637.02, 2793.83, 2959.96, 3135.96, 3322.44},
};

double calculateFrequency(int noteNumber, int octave) {

    return notes[octave][noteNumber - 1];
    // // Handle pause
    // if (noteNumber == 0) {
    //     return 0.0;
    // }

    // // Adjust note index for 1-based input
    // noteNumber = noteNumber - 1;
    // octave = octave - 1;
    // if (noteNumber != 0 && noteNumber != 2) {
    //   octave -= 1;
    // }
    // // Ensure note is within valid range
    // if (noteNumber < 0 || noteNumber >= 12) {
    //     return -1.0; // Indicate invalid note
    // }

    // // Ensure octave is valid
    // if (octave < 0 || octave > 8) {
    //     return -1.0; // Indicate invalid octave
    // }

    // // Calculate the frequency
    // double res =  55.00 * pow(2.0, (noteNumber + (12 * octave)) / 12.0); 
    // // round here to 2 decimal places
    // float b = round(res * 100.0) / 100.0;
    // return b;
}