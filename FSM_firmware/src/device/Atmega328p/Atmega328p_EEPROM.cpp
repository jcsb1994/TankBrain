#include "device/Atmega328p/Atmega328p_EEPROM.h"

void memory_interface::generateSaveAddresses()
{
    for (int i = 0; i < NB_SAVE_VALUES; i++)
    {
        _saveAddress[i] = (i * VALUES_TYPE_SIZE);
    }
}

void memory_interface::populateSavedValues()
{
    for (int adr_i = 0; adr_i < NB_SAVE_VALUES; adr_i++)
    {
        union eepromBytesToFloat
        {
            uint8_t byte[4];
            float eepromFloat;
        } u;

        for (uint8_t i = 0; i < VALUES_TYPE_SIZE; i++)
            u.byte[i] = EEPROM.read(_saveAddress[adr_i] + i);

        _savedValue[adr_i] = u.eepromFloat;
    }
}

void memory_interface::decrementCurrentIndex()
{
    if (_currentSaveIndex == 0)
        _currentSaveIndex = (NB_SAVE_VALUES - 1);
    else
        _currentSaveIndex--;
}

void memory_interface::incrementCurrentIndex()
{
    _currentSaveIndex++;
    if (_currentSaveIndex == NB_SAVE_VALUES)
        _currentSaveIndex = 0;
}

void memory_interface::saveToCurrentIndex(float val)
{
    unsigned char readingBytes[sizeof val];
    memcpy(readingBytes, &val, sizeof val);
    
    for (uint8_t i = 0; i < sizeof val; i++)
        EEPROM.update(this->getTargetAddress() + i, readingBytes[i]);
}