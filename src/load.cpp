#include "load.h"
#include "fs.h"

void handle_load(int r1, int r2, State *state) {
    if (state->songIndex == 4)
        return;
    
    if (r2 == 1) {
        tonefs header = get_fs();

        int count = header.number_of_songs;
        fs_read(header.song_offsets[0]);
    }
}

void finish_load_state() {

}