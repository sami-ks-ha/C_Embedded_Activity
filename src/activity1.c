#include "activity1.h"

/**
 * @brief initialise registers
 * 
 */

void peripheral_init(void)
{
	DDRB|=(1<<PB0);
	DDRD&=~(1<<PD0);
	PORTD|=(1<<PD0);
	DDRD&=~(2<<PD0);
	PORTD|=(2<<PD0);
}

/**
 * @brief && 2 buttons and proceed if both are on
 * 
 * @return uint16_t 
 */

uint16_t buttons()
{
    if((!(PIND&(1<<PD0))) & (!(PIND&(2<<PD0))))
        {
            PORTD|=(1<<PD6);
            return 1;
        }
        else
        {
            PORTD&=~(1<<PD6);
            return 0;
        }
}