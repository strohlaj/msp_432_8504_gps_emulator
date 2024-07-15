/*
 * gpios.h
 *
 *  Created on: Jul 14, 2024
 *      Author: AaronStrohl
 */

#ifndef GPIOS_H_
#define GPIOS_H_

#include "priority_queue.h"
#include "driverlib.h"

void init_gpios(void);

void toggle_keep_alive_led(void);

void turn_off_time_marked_pulse(void);

void turn_on_time_marked_pulse(void);

#endif /* GPIOS_H_ */
