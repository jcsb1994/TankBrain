#include "FSM/FSM.h"


void init_state_handler();

FSM::FSM(void initial_state(void))
{
    _UI = UI();
    _state_handler = initial_state;
}

FSM::~FSM()
{
}

event FSM::extract_incoming_event()
{
    event ev = _incoming_event;
    _incoming_event = event::nothing;
    return ev;
}

event FSM::poll()
{
    if (_incoming_event != event::nothing)
    {
        return extract_incoming_event();
    }

    // poll desired UI user inputs (tacts, encoders, etc.)
    _UI.poll_tacts();

    // get any event that occured in the polled input widgets
    _incoming_event = _UI.extract_event();


/*     if (incoming_UI_event)
    {
        Serial.print("FSM event");
        Serial.println(incoming_UI_event);
    } */

    return extract_incoming_event();
}


void FSM::handle_state()
{
    _state_handler();
}