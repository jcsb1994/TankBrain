#include "device/input_shift_register/74HC165.h"

void input_shift_reg_SPI_init()
{
    pinMode(LOAD_PIN, OUTPUT);
    SPI.setClockDivider(SPI_CLOCK_DIV128);
    SPI.setDataMode(SPI_MODE0);
    SPI.setBitOrder(MSBFIRST);
    SPI.begin();
}

void shift_reg_snapshot()
{
    PORTD &= ~(1 << LOAD_PIN);
    delay(1);
    PORTD ^= (1 << LOAD_PIN);
}

int transfer_shift_reg_data()
{
    int data = SPI.transfer(0x00);
    return data;
}