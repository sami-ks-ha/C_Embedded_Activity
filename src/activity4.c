#include "activity4.h"

/**
 * @brief initializes registers
 * 
 * @param ubrr_value 
 */
void USARTInit(uint16_t ubrr_value)
{
    //Set Baud Rate

    UBRR0L = ubrr_value;
    UBRR0H = (ubrr_value>>8)&0x00ff;
    UCSR0C = (1<<UMSEL00)|(1<<UCSZ01)|(1<<UCSZ00);

    //Enable rx and tx

    UCSR0B = (1<<RXEN0)|(1<<TXEN0)|(1<<RXCIE0)|(1<<TXCIE0);
}

/**
 * @brief transmits character
 * 
 * @param c 
 */
void USARTWriteChar(char c)
{
    //Wait until tx is ready
    while(!(UCSR0A & (1<<UDRE0)));
    UDR0=c;
}

/**
 * @brief Passes a string character by character to USARTWriteChar(char)
 * 
 * @param data 
 */
void USARTWritestring(char data[])
{
	int i =0;
	while (data[i] != 0x00)
	{
		USARTWriteChar(data[i]);
		i++;
	}
}