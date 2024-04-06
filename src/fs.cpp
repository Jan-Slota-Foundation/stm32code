#include <Arduino.h>
#include <EEPROM.h>
#include "fs.h"

tonefs init_fs() {

    tonefs fs;
    if (EEPROM.read(0) == 0x1C) {
        fs.number_of_songs = EEPROM.read(1);
        for(int i = 0; i < fs.number_of_songs; i++) {
            fs.song_offsets[i] = EEPROM.read(2 + i);
        }
        return fs;

    } else {
        fs.number_of_songs = 0;
        EEPROM.write(0, 0x1C);
        EEPROM.write(1, 0);
        return fs;
    }
    
}


Song fs_read(const int index) {
    int size = EEPROM.read(index);
    Song song;
    for(int i = 0; i < size; i++) {

        int memory_byte = index + 1 + i * 2;
        int memory_byte1 = index + 1 + i * 2 + 1;

        byte fir_byte = EEPROM.read(memory_byte);
        byte sec_byte = EEPROM.read(memory_byte1);

        byte note = fir_byte & 0x0F;
        byte octave = fir_byte >> 4;
        byte duration = sec_byte & 0x03;
        song.melody[i].note = note;
    }
    return song;
}


void fs_write(int index, const Song& song) {
    int size = MAX_NOTES;
    EEPROM.write(index, size);

    for(int i = 0; i < size; i++) {
        byte note = song.melody[i].note;
        byte octave = song.melody[i].octave;
        byte length = song.melody[i].duration;
        
        byte first_byte = (octave << 4) | note;
        byte second_byte = length & 0x03;

        int memory_byte = index + 1 + i * 2;
        int memory_byte1 = index + 1 + i * 2 + 1;
        
        EEPROM.write(memory_byte, first_byte);
        EEPROM.write(memory_byte1, second_byte);
    }
}
