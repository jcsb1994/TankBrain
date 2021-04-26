#include "FSM/tact.h"

//#######################################################################//
// Init of static variables
//#######################################################################//

int tact::_Count = 0;


//#######################################################################//
// tact class
//#######################################################################//

// Constructors
tact::tact(int assigned_pin) : _pin(assigned_pin)
{
    _Count++;
    _ID = _Count;
    pinMode(_pin, INPUT_PULLUP);
    input_shift_ptr = NULL;
    input_shift_used = 0;
}

tact::tact(int assigned_pin, input_shift_register &shift) : _pin(assigned_pin), input_shift_ptr(&shift)
{
    _Count++;
    _ID = _Count;
    input_shift_used++;
}

void tact::debounce()
{
    if (input_shift_used)
        input = (input_shift_ptr->data & (1 << _pin)) >> _pin;
    else
        input = digitalRead(_pin);

    if (input == 0)
    {
        if (integrator > 0)
            integrator--;
    }
    else if (integrator < MAXIMUM)
        integrator++;

    if (integrator == 0)
        _curr_debounced_input = 0;
    else if (integrator >= MAXIMUM)
    {
        integrator = MAXIMUM; // Defensive code
        _curr_debounced_input = 1;
    }
}

int tact::poll()
{

    tact::state = 0;

        if (!input_shift_used)
            _curr_debounced_input = digitalRead(tact::_pin);
        else
            _curr_debounced_input = ((input_shift_ptr->data & (1 << _pin)) >> _pin);

    //----------------------------------------------------------------

    if (!_curr_debounced_input && _last_debounced_input && !is_pressed)
    {
        is_pressed = true;
        long_press_counter = millis();
        tact::state = SHORT_EFFECT_REQUIRED;
    }

    //----------------------------------------------------------------

    if (!_last_debounced_input && _curr_debounced_input && is_pressed)
    {
        if (!long_effect_done)
            tact::state = RELEASE_EFFECT_REQUIRED;

        long_effect_done = 0;
        long_press_counter = 0;
        is_pressed = 0;
    }

    //----------------------------------------------------------------

    else if (is_pressed && !long_effect_done && ((millis() - long_press_counter) >= LONG_PRESS_DELAY))
    {
        tact::state = LONG_EFFECT_REQUIRED;
        long_effect_done++;
        long_press_counter = 0;
    }

    //----------------------------------------------------------------

    tact::_last_debounced_input = tact::_curr_debounced_input;

    return tact::state;
}

