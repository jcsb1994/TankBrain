//***********************************************************************************
// Copyright 2021 jcsb1994
// Written by jcsb1994
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

//***********************************************************************************
//
// Description:
//    This file provides a high level interface for Atmega328p Timers
//
//***********************************************************************************
//
//  ATMEGA328P TIMERS: 
//    Timer0
//    Timer1
//    Timer2
//    Watchdog Timer
//
//***********************************************************************************


#ifndef ATMEGA328P_TIMERS_H
#define ATMEGA328P_TIMERS_H

#include <Arduino.h>
#include <avr/interrupt.h>

#define WDT_CONFIG 0
#define TIMER_TWO_CONFIG 0
#define TIMER_ONE_CONFIG 0
#define TIMER_ZERO_CONFIG 0

/*##################################################
            WDT
##################################################*/

#if WDT_CONFIG

extern volatile uint8_t wdt_counter;

/***************************************************************************
 * WDT_setup function
 * This function sets the appropriate registers for WDT to be turned on.
 ***************************************************************************/

void WDT_setup();

#endif

/*##################################################
            TIMER1
##################################################*/
#if TIMER_ONE_CONFIG

void timer1_setup();

void timer0_setup();

/***************************************************************************
 * timer1_setup function
 * This function sets the appropriate registers for WDT to be turned on.
 ***************************************************************************/

#endif

#endif // ATMEGA328P_TIMERS_H