

#include "main.h"
#include "FSM/states.h"
#include "FSM/events.h"

#define TFT_CS 10 // define chip select pin
#define TFT_DC 9  // define data/command pin
#define TFT_RST 8 // define reset pin, or set to -1 and connect to Arduino RESET pin

Adafruit_ST7789 tft = Adafruit_ST7789(TFT_CS, TFT_DC, TFT_RST);

struct tact_link tact_links[TACT_NB]{{0, nothing, up, nothing},
                                     {1, nothing, left, nothing},
                                     {2, nothing, enter, nothing},
                                     {3, nothing, down, nothing},
                                     {4, nothing, right, nothing}};

bool refreshFlag = false;
bool valuesRefreshFlag = false;

volatile uint8_t timerOneFlagIterator = false;

ISR(TIMER0_COMPA_vect)
{
    timerOneFlagIterator++;
}

void setup()
{
    Serial.begin(9600);
    pinMode(DEBUG_LED_PIN, OUTPUT);

    tft.init(240, 240, SPI_MODE2); // Init ST7789 display 240x240 pixel
    tft.setRotation(2);
    tft.setTextWrap(true);
}

FSM machine(init_state_handler);

void loop()
{
    machine.handle_state();
}
