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
//    This file provides a high level interface for Atmega328p eeprom.
//
//***********************************************************************************

#ifndef ATMEGA328P_EEPROM_H
#define ATMEGA328P_EEPROM_H

#include <Arduino.h>
#include <EEPROM.h>

#define NB_SAVE_VALUES (4)
#define MEMORY_ADR_SIZE (sizeof(double))

class MemoryInterface {
private:
    int _writeAddresses[NB_SAVE_VALUES];
    uint8_t _currentWriteIndex;            // Which of the address index is currently targeted

    void _generateWriteAddresses();

public:
    MemoryInterface() {
        _generateWriteAddresses();
    }
    ~MemoryInterface() {}

    void incrementSaveIndex();
    void decrementSaveIndex();
    uint8_t getSaveIndex() {return _currentWriteIndex; }

    // uint8_t saveStruct(KneeAssessment_t assessment);
    // KneeAssessment_t readStruct(uint8_t saveIdx);
};

#endif 