#include "load.h"
#include "fs.h"
#include "display.h"

void handle_load(int r1, int r2, State *state) {
    if (state->songIndex == 4)
        return;
    
    if (r2 == 1) {
        displayNumber(state->songIndex);
        tonefs header = get_fs();

        int count = header.number_of_songs;
        Song s = fs_read(header.song_offsets[0]);
        state->songs[state->songIndex++] = s;
        state->state = SINGLE_NOTE;
        return;
    }
}

void finish_load_state() {

}