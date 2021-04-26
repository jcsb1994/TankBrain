//***********************************************************************************
// Copyright 2021 jcsb1994
// Written by jcsb1994
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//
//***********************************************************************************
//
// Description:
//    This file provides a low level interface for tact switch input management.
//
//***********************************************************************************


#ifndef TACT_H
#define TACT_H

#include <Arduino.h>
#include "../FSM/events.h"

/*##################################################
            MACROS
##################################################*/

#define TACT_NB 5
#define LONG_PRESS_DELAY (400)
#define BUTTON_ACTIVE_STATE_CONFIG 0
// Debounce macros
#define DEBOUNCED 1
#define NOT_DEBOUNCED 0
#define DEBOUNCE_TIME 0.3
#define SAMPLE_FREQUENCY 6
#define MAXIMUM (SAMPLE_FREQUENCY*DEBOUNCE_TIME)
// Polling macros
#define SHORT_EFFECT_REQUIRED (1)
#define RELEASE_EFFECT_REQUIRED (2)
#define LONG_EFFECT_REQUIRED (3)
#define TACT_PIN_UNASSIGNED (-1)

/*##################################################
            DECLARATION
##################################################*/

struct input_shift_register
{
    bool not_used;
    int data;
    int *ptr_to_data;
};


//#######################################################################//
// tact_link struct
//      used to link the events to different types of inputs from the tact.
//      tact_links object is defined in main
//#######################################################################//

struct tact_link
{
    int pin;

    event short_press;
    event release_press;
    event long_press;
    tact_link(int pin,
        event short_press_event = nothing,
        event release_press_event = nothing,
        event long_press_event = nothing) : pin(pin),
        short_press(short_press_event),
        release_press(release_press_event),
        long_press(long_press_event) {}
};

extern struct tact_link tact_links[TACT_NB];

//#######################################################################//
// tact class
//      manages tactile buttons
//#######################################################################//

class tact
{

private:
    int _pin = TACT_PIN_UNASSIGNED;
    static int _Count;  // counts how many tacts are created
    unsigned int _ID;   // sets a specific ID for each tact in order of creation

    short state = 0;    // carries the current state after polling

    bool input_shift_used;
    input_shift_register *input_shift_ptr;

    // Debounce variables
    volatile unsigned int input = 1; // Current state of the tact switch
    volatile unsigned int integrator;
    volatile bool _curr_debounced_input = 1; // Output of the algorithm
    volatile bool _last_debounced_input = 1;

    unsigned long long_press_counter = 0;
    bool long_effect_done = 0;
    bool is_pressed = false;    // Keeps track of which button is pressed during poll (useful when simultaneousButtonPressesConfig)

public:
    tact() {};
    tact(int assigned_pin);                              // Constructor
    tact(int assigned_pin, input_shift_register &shift); // Overloaded constructor for tacts linked to a shift register chip

    void debounce();

    int poll();

    static int *pressOutput;

    void setPin(int assigned_pin)
    {
        tact::_pin = assigned_pin;
    }

    int getPin() {
        return tact::_pin;
    }

};

#endif // Header guard