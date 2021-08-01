#include "activity2.h"

/**
 * @brief initializes registers
 * 
 */
void adc_init()
{
    ADMUX|=(1<<REFS0);
    ADCSRA=(1<<ADEN)|(7<<ADPS0);
}

/**
 * @brief converts input from potentiometer to digital value
 * 
 * @param ch 
 * @return uint16_t 
 */

uint16_t adc_read(uint8_t ch)
{
    ADMUX&=0xf8;
    ch=ch&0b00000111;
    ADMUX|=ch;
    ADCSRA|=(1<<ADSC);
    while(!(ADCSRA&(1<<ADIF)));
    ADCSRA|=(1<<ADIF);
    return (ADC);
}