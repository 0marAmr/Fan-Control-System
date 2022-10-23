/*
 * timer.h
 *
 *  Created on: Oct 10, 2022
 *      Author: Omar
 */

#ifndef _TIMER_H_
#define _TIMER_H_

#include "../../std_types.h"

#define TIMER0_MAX_COUNT 255
/* Timer 0 */
#define TCNT0 	(*((volatile uint8 * const)0x52))
#define OCR0    (*((volatile uint8 * const)0x5C))
#define DDRB    (*((volatile uint8 * const)0x37))
#define TCCR0    (*((volatile uint8 * const)0x53))

/* TCCR0 */
#define FOC0    7
#define WGM00   6
#define COM01   5
#define COM00   4
#define WGM01   3
#define CS02    2
#define CS01    1
#define CS00    0


/* PORTB */
#define PB7     7
#define PB6     6
#define PB5     5
#define PB4     4
#define PB3     3
#define PB2     2
#define PB1     1
#define PB0     0

void PWM_timer0Start(uint8 duty_cycle);


#endif /* TIMER_H_ */
