#ifndef FS_H
#define FS_H
    #include "song.h"
    typedef struct tonefs {
        int number_of_songs;
        int song_offsets[10]; // Max 10 songs
    } tonefs;

    tonefs get_fs();

    Song fs_read(const int offset);
    void fs_write(const Song& song);
    void update_fs(const tonefs& fs);
    int calculate_new_offset(const tonefs& fs);
    void nuke_fs();
    void init_fs();
#endif