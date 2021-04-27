#ifndef MAIN_H
#define MAIN_H

// Core Files
#include <Arduino.h>
#include <SPI.h>
#include <Wire.h>
#include <EEPROM.h>

// Env files
#include "FSM/FSM.h"                // Custom State Machine Class
#include "device/Atmega328p/Atmega328p_Timers.h"  
#include "device/Atmega328p/Atmega328p_EEPROM.h"
#include "device/Atmega328p/Atmega328p_Sleep.h"
#include "debug_environment_settings.h"

// Ext libraries (used in current app, added from the platformio.ini file)
#include <Adafruit_GFX.h>
#include <HX711_ADC.h>
#include <Adafruit_ST7789.h>    // Includes Adafruit_GFX.h

// App Specific Files
#include "dialBitmap.h"

// ----------------------------------------------------------------------
//      GLOBAL
// Global variables, declared extern here to be accessed by states source files
// ----------------------------------------------------------------------

extern FSM machine;
extern bool refreshFlag;
extern bool valuesRefreshFlag;

extern volatile uint8_t timerOneFlagIterator;

extern Adafruit_ST7789 tft;

#endif // MAIN_H