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
//    This file provides a low level interface for the 74HC165 input register.
//
//***********************************************************************************


#ifndef _74HC165_H
#define _74HC165_H


#include <stdint.h>
#include <SPI.h>


#define LOAD_PIN 5


/***************************************************************************
 * SPI_init function
 * 
 * SPI protocol is initialized.
 * SPI is needed to get data from the 74hc165 shift registers
 * 
 ***************************************************************************/

void SPI_init();

/***************************************************************************
 * inputShiftSnapShot function
 * 
 * 1) Turn the loadPin HIGH for a millisecond, saves the state of the input pins
 * at a given moment
 * 2) 1 empty byte is transfered for each shift register via the SPI protocol
 *    and received exchange byte is stored in the shift register's data member.
 * 
 ***************************************************************************/

void inputShiftSnapShot();

#endif