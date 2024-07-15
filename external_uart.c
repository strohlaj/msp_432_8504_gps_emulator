#include "external_uart.h"

/*
 * we assume the MCLK is operating off of the DCO and the DCO is tuned to
 * 12MHzUART Configuration Parameter. These are the configuration parameters to
 * make the eUSCI A UART module to operate with a 115200 baud rate. These
 * values were calculated using the online calculator that TI provides
 * at:
 *http://software-dl.ti.com/msp430/msp430_public_sw/mcu/msp430/MSP430BaudRateConverter/index.html
 */
const eUSCI_UART_Config uartConfig =
{
    EUSCI_A_UART_CLOCKSOURCE_SMCLK, // SMCLK Clock Source
    6, // BRDIV = 78
    8, // UCxBRF = 2
    32, // UCxBRS = 0
    EUSCI_A_UART_NO_PARITY, // No Parity
    EUSCI_A_UART_LSB_FIRST, // MSB First
    EUSCI_A_UART_ONE_STOP_BIT, // One stop bit
    EUSCI_A_UART_MODE, // UART mode
    EUSCI_A_UART_OVERSAMPLING_BAUDRATE_GENERATION // Oversampling
};


void init_uart(void) {
    MAP_GPIO_setAsPeripheralModuleFunctionInputPin(GPIO_PORT_P3,
               GPIO_PIN3 | GPIO_PIN4, GPIO_PRIMARY_MODULE_FUNCTION);

    MAP_UART_initModule(EUSCI_A2_BASE, &uartConfig);

    MAP_UART_enableModule(EUSCI_A2_BASE);

    MAP_UART_enableInterrupt(EUSCI_A2_BASE, EUSCI_A_UART_RECEIVE_INTERRUPT);

}

void uart_send(uint8_t* data, uint8_t size) {
    for (int x = 0; x < size; x++) {
        uint8_t dataToSend = *data;
        MAP_UART_transmitData(EUSCI_A2_BASE, dataToSend);
        data++;
    }
}

