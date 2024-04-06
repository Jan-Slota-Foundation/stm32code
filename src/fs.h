#ifndef FS_H
#define FS_H
    #include "song.h"
    typedef struct tonefs {
        int number_of_songs;
        int song_offsets[10]; // Max 10 songs
        int next_offset;
    } tonefs;

    tonefs init_fs();

    Song fs_read(const int offset);
    void fs_write(int offset, const Song& song);
#endif