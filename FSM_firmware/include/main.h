#ifndef MAIN_H
#define MAIN_H

// Core Files
#include <Arduino.h>
#include <SPI.h>
#include <Wire.h>
#include <EEPROM.h>
#include "FSM/FSM.h"                // Custom State Machine Class

#include "device/Atmega328p/Atmega328p_Timers.h"  
#include "device/Atmega328p/Atmega328p_EEPROM.h"

// Ext libraries (used in current app, added from the platformio.ini file)
#include <Adafruit_GFX.h>
#include <HX711_ADC.h>
#include <Adafruit_ST7789.h>    // Includes Adafruit_GFX.h

// App Specific Files
#include "dialBitmap.h"
#include "bracket.h"

// ----------------------------------------------------------------------
//      GLOBAL
// Global variables, declared extern here to be accessed by states source files
// ----------------------------------------------------------------------

#define DEBUG_LED_PIN (13)

extern FSM machine;
extern Adafruit_ST7789 tft;

extern bool refreshFlag;
extern bool valuesRefreshFlag;

extern volatile uint8_t timerOneFlagIterator;

#endif // MAIN_H