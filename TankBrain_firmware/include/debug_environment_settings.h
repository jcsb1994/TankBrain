#ifndef __DEBUG_ENV_SETTINGS_H__

#define __USING_SERIAL_DEBUG_MODE__ 0

#define __USING_DEBUG_MODE__ 1

#if __USING_DEBUG_MODE__
#include "avr8-stub.h"
#define DEBUG_LED_PIN (13)   // cannot use TFT screen when enabled (or SPI protocol at all)
#endif


#endif