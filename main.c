#include "activity1.h"
#include "activity2.h"
#include "activity3.h"
#include "activity4.h"

#include "activity1.c"
#include "activity2.c"
#include "activity3.c"
#include "activity4.c"

#include <avr/io.h>
#include <util/delay.h>

/**
 * @brief Main function where code is executed
 *
 * @return int
 */

int main(void)
{
	// Initializing registers required for various functions
    peripheral_init();
	adc_init();
    pwm_init();
    USARTInit(103);

	//Messages showing temperature detected by sensor
    uint16_t temp=0,previous=0;
    char data1[]="Temperature:20°C\n";
    char data2[]="Temperature:25°C\n";
    char data3[]="Temperature:29°C\n";
    char data4[]="Temperature:33°C\n";

    while(1)
    {
        if (!buttons())
        {
            continue;
        }
        else
        {
            while(1)
            {   previous=temp;
                temp=adc_read(0);
                if (temp==previous)
                {
                    continue;
                }
                if (temp<=200)
                {
                    OCR0A=51;
                    USARTWritestring(data1);
                    _delay_ms(200);
                }
                else if(temp<=500)
                {
                    OCR0A=102;
                    USARTWritestring(data2);
                    _delay_ms(200);
                }
                else if(temp<=700)
                {
                    OCR0A=179;
                    USARTWritestring(data3);
                    _delay_ms(200);
                }
                else
                {
                    OCR0A=243;
                    USARTWritestring(data4);
                    _delay_ms(200);
                }
            }
        }
    }
    return 0;
}
