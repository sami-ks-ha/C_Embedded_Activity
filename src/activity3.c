#include "activity3.h"

/**
 * @brief uses value from adc to make pwm signal of corresponding duty cycle
 * 
 */
void pwm_init()
{
    TCCR0A|=(1<<COM0A1)|(1<<WGM01)|(1<<WGM00);
    TCCR0B|=(1<<CS01)|(1<<CS00);
    DDRD|=(1<<PD6);
}