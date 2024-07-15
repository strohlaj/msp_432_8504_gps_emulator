/*
 * button.h
 *
 *  Created on: Jul 14, 2024
 *      Author: AaronStrohl
 */

#ifndef BUTTON_H_
#define BUTTON_H_
#include "driverlib.h"
#include "priority_queue.h"

void init_buttons(void);
void enable_button(void);
void disable_button(void);


#endif /* BUTTON_H_ */
