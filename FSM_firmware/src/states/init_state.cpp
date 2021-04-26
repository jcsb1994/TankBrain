
#include "main.h"
#include "FSM/states.h"
#include "FSM/events.h"

#define BUZZER_PIN 7
int melody[] = {523, 329, 659};  //Speaker Setup Sounds
int noteDurations[] = {8, 4, 2}; // note durations: 4 = quarter note, 8 = eighth note, etc.

// ----------------------------------------------------------------------
//      INIT STATE
// ----------------------------------------------------------------------

void init_state_handler()
{
    /*     if (!.init())
    {
        tft.print("Error");
        while (1)
            ;
    } */

    tft.fillScreen(ST77XX_YELLOW);
    tft.setCursor(30, 30);
    tft.setTextSize(3);
    tft.setTextColor(ST77XX_WHITE);
    tft.print("Hello");

/*     for (int thisNote = 0; thisNote < 3; thisNote++)
    {
        int noteDuration = 1000 / noteDurations[thisNote];
        tone(BUZZER_PIN, melody[thisNote], noteDuration);

        int pauseBetweenNotes = noteDuration * 1.30;
        delay(pauseBetweenNotes);
        noTone(BUZZER_PIN);
    }
    pinMode(BUZZER_PIN, INPUT); // Hi Z stops hissing */

    machine.set_state(main_state_handler);
    machine.update_widget_map_size(2,3);

    refreshFlag = true;
}
