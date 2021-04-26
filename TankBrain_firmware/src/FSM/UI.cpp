#include "FSM/UI.h"

UI::UI()
{
    for (int i = 0; i < TACT_NB; i++)
    {
        _Tacts[i] = tact(tact_links[i].pin);
    }
}

UI::~UI()
{
}

void UI::poll_tacts()
{

    for (int i = 0; i < TACT_NB; i++)
    {
        int currentState;
        if (_Tacts[i].getPin() != TACT_PIN_UNASSIGNED)
        {
            currentState = _Tacts[i].poll();
        }
        switch (currentState)
        {
        case SHORT_EFFECT_REQUIRED:
            _incoming_event = tact_links[i].short_press;
            break;

        case RELEASE_EFFECT_REQUIRED:
            _incoming_event = tact_links[i].release_press;
            break;

        case LONG_EFFECT_REQUIRED:
            _incoming_event = tact_links[i].long_press;
            break;

        default:
            break;
        }

    }
}

event UI::extract_event()
{
    if (_incoming_event)
    {
        event event = _incoming_event;
        _incoming_event = nothing;
        return event;
    }
    else
        return nothing;
}
