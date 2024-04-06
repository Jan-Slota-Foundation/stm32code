#include <Arduino.h>
#include <EEPROM.h>
#include "fs.h"

tonefs get_fs() {
    tonefs fs;
    if (EEPROM.read(0) == 0x1C) {
        fs.number_of_songs = EEPROM.read(1);
        fs.next_offset = EEPROM.read(2);
        for(int i = 0; i < fs.number_of_songs; i++) {
            fs.song_offsets[i] = EEPROM.read(3 + i);
        }
        return fs;
    } else {
        fs.number_of_songs = 0;
        EEPROM.write(0, 0x1C);
        EEPROM.write(1, 0);
        EEPROM.write(2, 15);
        for(int i = 0; i < 10; i++) {
            EEPROM.write(3 + i, 0);
        }
        return fs;
    }
}

void update_fs(const tonefs& fs) {
    EEPROM.write(1, fs.number_of_songs);
    EEPROM.write(2, fs.next_offset);
    for(int i = 0; i < fs.number_of_songs; i++) {
        EEPROM.write(3 + i, fs.song_offsets[i]);
    }
}

Song fs_read(const int index) {
    int size = EEPROM.read(index);
    int tempo = EEPROM.read(index + 1);
    Song song;
    song.tempo = tempo * 10;

    for(int i = 0; i < size; i++) {

        int memory_byte = index + 2 + i * 2;
        int memory_byte1 = index + 2 + i * 2 + 1;

        byte fir_byte = EEPROM.read(memory_byte);
        byte sec_byte = EEPROM.read(memory_byte1);

        byte note = fir_byte & 0x0F;
        byte octave = fir_byte >> 4;
        byte duration = sec_byte & 0x03;
    
        song.melody[i].note = note;
        song.melody[i].octave = octave;
        song.melody[i].duration = duration;
    }
    return song;
}

void fs_write(const Song& song) {
    int size = MAX_NOTES;

    // calculatr update value for update_fs
    tonefs fs = get_fs();
    int index = fs.next_offset;
    int newIndex = index + 2 + size * 2;
    tonefs new_fs = fs;
    
    new_fs.number_of_songs++;
    new_fs.song_offsets[new_fs.number_of_songs] = index;
    new_fs.next_offset = newIndex;

    EEPROM.write(index, size);
    EEPROM.write(index + 1, (song.tempo / 10));

    for(int i = 0; i < size; i++) {
        byte note = song.melody[i].note;
        byte octave = song.melody[i].octave;
        byte length = song.melody[i].duration;
        
        byte first_byte = (octave << 4) | note;
        byte second_byte = length & 0x03;

        int memory_byte = index + 2 + i * 2;
        int memory_byte1 = index + 2 + i * 2 + 1;
        
        EEPROM.write(memory_byte, first_byte);
        EEPROM.write(memory_byte1, second_byte);
    }
}
