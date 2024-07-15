#ifndef EXTERNAL_UART_H_
#define EXTERNAL_UART_H_

#include "driverlib.h"


void init_uart(void);

void uart_send(uint8_t* data, uint8_t size);


#endif /* EXTERNAL_UART_H_ */
