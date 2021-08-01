#ifndef __ACTIVITY_2_H__
#define __ACTIVITY_2_H__

#define F_CPU 16000000UL 	/**< Clock Frequency of MCU is 16 MHz */
#include <avr/io.h>

/**
 * @brief initializes registers
 * 
 */
void adc_init();

/**
 * @brief converts input from potentiometer to digital value
 * 
 * @param ch 
 * @return uint16_t 
 */
uint16_t adc_read(uint8_t ch);

#endif /* __ACTIVITY_2_H__ */