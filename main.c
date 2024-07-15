#include "msp.h"
#include "stdbool.h"
#include "stdio.h"
#include "stdint.h"
#include "driverlib.h"
#include "priority_queue.h"
#include "external_uart.h"
#include "gps_structures.h"
#include "timed_pulse.h"
#include "button.h"
#include "gpios.h"

typedef enum _APP_STATE {
    TIMER_STOPPED,
    TIMER_STARTED,
} APP_STATE;

APP_STATE STATE = TIMER_STOPPED;


void main(void)
{

    /* Stop watchdog timer */
    MAP_WDT_A_holdTimer();


    init_queue();
    init_gpios();

    uint32_t smclkFreq1 = CS_getSMCLK();
    uint32_t hsmclkFreq1 = CS_getHSMCLK();

    // CS_DCO_FREQUENCY_12
    // CS_setDCOFrequency(CS_DCO_FREQUENCY_12);
    CS_setDCOCenteredFrequency(CS_DCO_FREQUENCY_12);

    uint32_t smclkFreq2 = CS_getSMCLK();
    uint32_t hsmclkFreq2 = CS_getHSMCLK();

    MAP_CS_setReferenceOscillatorFrequency(CS_REFO_128KHZ);
    MAP_CS_initClockSignal(CS_ACLK, CS_REFOCLK_SELECT, CS_CLOCK_DIVIDER_128);

    init_timer_a();
    init_buttons();
    init_uart();


    /* Enabling MASTER interrupts */
    MAP_Interrupt_enableMaster();

    // MAP_UART_enableModule(EUSCI_A2_BASE, EUSCI_A_UART_RECEIVE_INTERRUPT);
    if (STATE == TIMER_STOPPED) {
        printf("%s", "Started timer");
        STATE = TIMER_STARTED;
        MAP_Timer_A_startCounter(TIMER_A0_BASE, TIMER_A_UP_MODE);
    }

    while(1) {
        queue_item refEvent;
        if (dequeue(&refEvent)) {
            uint16_t timer_a_count = MAP_Timer_A_getCounterValue(TIMER_A0_BASE);
            switch (refEvent.eventId) {
                case KEEP_ALIVE_LED: {
                    toggle_keep_alive_led();
                    printf("Timer A counter value at KEEP_ALIVE_LED event: %d \n", timer_a_count);
                    break;
                }
                case BUTTON_PRESSED: {
                    start_gps_time_marked_pulse();
                    printf("Timer A counter value at BUTTON_PRESSED event: %d \n", timer_a_count);
                    break;
                }
                case TIME_MARKED_PULSE_COMPLETE: {
                    // Build 8504 message
                    Person_t aaron = {.age = 87, .gender = MALE};
                    // Send it out of the uart
                    uart_send((uint8_t*)&aaron, sizeof(Person_t));
                    printf("Timer A counter value at TIME_MARKED_PULSE_COMPLETE event: %d \n", timer_a_count);
                }
            }
        }



//        if (interruptCounter > 25) {
//            MAP_GPIO_setOutputLowOnPin(GPIO_PORT_P1, GPIO_PIN0);
//            MAP_GPIO_setOutputLowOnPin(GPIO_PORT_P2, GPIO_PIN1);
//            MAP_GPIO_setOutputLowOnPin(GPIO_PORT_P2, GPIO_PIN2);
//            MAP_Timer_A_stopTimer(TIMER_A0_BASE);
//            MAP_Timer_A_clearTimer(TIMER_A0_BASE);
//        }
    }
}
