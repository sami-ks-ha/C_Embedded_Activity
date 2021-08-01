#ifndef __ACTIVITY_3_H__
#define __ACTIVITY_3_H__

#define F_CPU 16000000UL 	/**< Clock Frequency of MCU is 16 MHz */
#include <avr/io.h>

/**
 * @brief uses value from adc to make pwm signal of corresponding duty cycle
 * 
 * @param[in] delay_time Delay in Micro seconds
 * 
 */
void pwm_init();

#endif /* __ACTIVITY_3_H__ */