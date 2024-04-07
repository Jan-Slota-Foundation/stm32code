#include "runner.h"
#include "main.h"
#include "button.h"
#include "single_note.h"
#include "scale.h"
#include "complex.h"
#include "online.h"
#include "save.h"
#include "stream.h"

State state;
Button b1;
Button b2;

void setup_runner(){
    state.state = SINGLE_NOTE;
    state.playing = false;
    state.lastState = NONE;
    b1 = init_button(BUTTON_MIDDLE);
    b2 = init_button(BUTTON_RIGHT);
}

void handle_state(int change)
{
    if (change == 1)
    {
        state.state = static_cast<RunnerStates>((state.state + 1) % 7);
    }
    else if (change == 2)
    {
        state.state = static_cast<RunnerStates>((state.state - 1 + 7) % 7);
    }
}

void handle_leds()
{
    switch (state.state)
    {
    case SINGLE_NOTE:
        digitalWrite(LED_1, LED_ON);
        digitalWrite(LED_2, LED_OFF);
        digitalWrite(LED_3, LED_OFF);
        break;
    case SCALE:
        digitalWrite(LED_1, LED_OFF);
        digitalWrite(LED_2, LED_ON);
        digitalWrite(LED_3, LED_OFF);
        break;
    case COMPLEX_RECORD:
        digitalWrite(LED_1, LED_ON);
        digitalWrite(LED_2, LED_ON);
        digitalWrite(LED_3, LED_OFF);
        break;
    case WRITE_PLAY:
        digitalWrite(LED_1, LED_OFF);
        digitalWrite(LED_2, LED_OFF);
        digitalWrite(LED_3, LED_ON);
        break;
    case STREAM:
        digitalWrite(LED_1, LED_ON);
        digitalWrite(LED_2, LED_OFF);
        digitalWrite(LED_3, LED_ON);
        break;
    case SAVE:
        digitalWrite(LED_1, LED_OFF);
        digitalWrite(LED_2, LED_ON);
        digitalWrite(LED_3, LED_ON);
        break;
    case LOAD:
        digitalWrite(LED_1, LED_ON);
        digitalWrite(LED_2, LED_ON);
        digitalWrite(LED_3, LED_ON);
        break;

    default:
        break;
    }
}

void handle_states(int r1, int r2)
{
    switch (state.state)
    {
    case SINGLE_NOTE:
        handle_single_note(r1, r2, &state);
        break;

    case SCALE:
        handle_scale(r1, r2, &state);
        break;

    case COMPLEX_RECORD:
        handle_complex(r1, r2, &state);
        break;

    case WRITE_PLAY:
        handle_online(r1, r2, &state);
        break;

    case STREAM:
        handle_stream(r1, r2, &state);
        break;

    case SAVE:
        handle_save(r1, r2, &state);
        break;

    case LOAD:
        break;

    default:
        break;
    }
}

void handle_state_change(int r1, int r2)
{
    switch (state.lastState)
    {
    case SINGLE_NOTE:
        finish_single_note_state();
        break;

    case SCALE:
        finish_scale_state();
        break;

    case COMPLEX_RECORD:
        finish_complex_state();
        break;

    case WRITE_PLAY:
        finish_online_state();
        break;

    case STREAM:
    finish_stream_state();
        break;

    case SAVE:
        finish_save_state();
        break;

    case LOAD:
        break;

    default:
        break;
    }
}

void run(int change)
{
    int r1 = update_button(&b1);
    int r2 = update_button(&b2);

    handle_state(change);

    //Serial.println(state.state);

    if (state.state != state.lastState)
    {
        handle_state_change(r1, r2);
        handle_leds();
        state.lastState = state.state;
    }

    handle_states(r1, r2);
}