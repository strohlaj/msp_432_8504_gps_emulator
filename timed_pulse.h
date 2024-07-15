

#ifndef TIMED_PULSE_H_
#define TIMED_PULSE_H_

#include "priority_queue.h"
#include "driverlib.h"
#include "button.h"
#include "gpios.h"

void init_timer_a(void);

void start_gps_time_marked_pulse(void);

#endif /* TIMED_PULSE_H_ */
