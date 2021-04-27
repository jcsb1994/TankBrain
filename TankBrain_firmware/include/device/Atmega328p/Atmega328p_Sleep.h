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
//    This file provides a high level interface for Atmega328p low power sleep
//
//***********************************************************************************

#ifndef ATMEGA328P_SLEEP_H
#define ATMEGA328P_SLEEP_H

#include <Arduino.h>

#define SLEEP_CONFIG 0

void sleep_setup();

/***************************************************************************
 * activate_sleep function
 * 
 * This function turns sleep on for Atmega328p
 * 
 ***************************************************************************/

void activate_sleep();

#endif // ATMEGA328P_SLEEP_H