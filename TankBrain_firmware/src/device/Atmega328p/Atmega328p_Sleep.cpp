#include "device/Atmega328p/Atmega328p_Sleep.h"

/*##################################################
            SLEEP
##################################################*/

void sleep_setup()
{
    //ENABLE SLEEP - this enables the sleep mode
    SMCR |= (1 << 2); //power down mode
    SMCR |= 1;        //enable sleep
}

void activate_sleep()
{

    ADCSRA |= (1 << 7); // Disable ADC - don't forget to flip back after waking up if using ADC in your application

    MCUCR |= (3 << 5);                      //set both BODS and BODSE at the same time
    MCUCR = (MCUCR & ~(1 << 5)) | (1 << 6); //then set the BODS bit and clear the BODSE bit at the same time
    __asm__ __volatile__("sleep");          //in line assembler to go to sleep
    
    ADCSRA |= (1 << 7);                     //re enable ADC
}
