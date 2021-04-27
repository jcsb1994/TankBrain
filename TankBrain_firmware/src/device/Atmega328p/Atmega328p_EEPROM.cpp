#include "device/Atmega328p/Atmega328p_EEPROM.h"


void MemoryInterface::_generateWriteAddresses() {
    for (int i = 0; i < NB_SAVE_VALUES; i++) {
        _writeAddresses[i] = (i * MEMORY_ADR_SIZE);
    }
}

void MemoryInterface::decrementSaveIndex()
{
    if (_currentWriteIndex == 0)
        _currentWriteIndex = (NB_SAVE_VALUES - 1);
    else
        _currentWriteIndex--;
    if (_currentWriteIndex >= NB_SAVE_VALUES)
        _currentWriteIndex = 0;

}

void MemoryInterface::incrementSaveIndex()
{
    _currentWriteIndex++;
    if (_currentWriteIndex >= NB_SAVE_VALUES)
        _currentWriteIndex = 0;
}

// uint8_t MemoryInterface::saveAssessment(KneeAssessment_t assessment) {
//     EEPROM.put(_writeAddresses[_currentWriteIndex++], assessment);
//     if (_currentWriteIndex >= NB_SAVE_VALUES) {
//         _currentWriteIndex = 0;
//     }
// }

// KneeAssessment_t MemoryInterface::readAssessment(uint8_t saveIdx) {
//     if (_currentWriteIndex >= NB_SAVE_VALUES) 
//         _currentWriteIndex = (NB_SAVE_VALUES-1); 
//     KneeAssessment_t assess;
//     EEPROM.get(_writeAddresses[saveIdx], assess);
//     if (assess.ID > 999) {
//         assess.ID = 0;
//     }
//     return assess;
// }