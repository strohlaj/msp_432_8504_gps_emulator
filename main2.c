/*******************************************************************************
 * MSP432 PWM TA1.1-2, Up/Down Mode, DCO SMCLK
 *
 * Description: Toggle P1.0 using software and TA_0 ISR. Timer0_A is
 * configured for up mode, thus the timer overflows when TAR counts
 * to CCR0. In this example, CCR0 is loaded with 0x2DC6 which makes the LED
 * toggle every half a second..
 * ACLK = n/a, MCLK = SMCLK = default DCO ~1MHz
 * TACLK = SMCLK/64
 *
 *         MSP432P401
 *      -------------------
 *  /|\|                   |
 *   | |                   |
 *   --|RST                |
 *     |                   |
 *     |               P1.0|-->LED
 *     |                   |
 *
*******************************************************************************/
/* DriverLib Includes */
#include "driverlib.h"
#include "stdio.h"

/* Timer_A UpMode Configuration Parameter */
const Timer_A_UpModeConfig upConfig =
{
        TIMER_A_CLOCKSOURCE_ACLK,                // ACLK Clock Source
        TIMER_A_CLOCKSOURCE_DIVIDER_1,           // SMCLK/1 = 3MHz
        10000,                                   // 5000 tick period
        TIMER_A_TAIE_INTERRUPT_DISABLE,         // Disable Timer interrupt
        TIMER_A_CCIE_CCR0_INTERRUPT_ENABLE ,    // Enable CCR0 interrupt
        TIMER_A_DO_CLEAR                        // Clear value
};

typedef enum _APP_STATE2 {
    MSG_WAIT,
    TIMER_MSG_REC,
} APP_STATE2;

APP_STATE2 STATE2 = MSG_WAIT;

int main2(void)
{
    /* Stop WDT  */
    // MAP_WDT_A_holdTimer();

    MAP_CS_setReferenceOscillatorFrequency(CS_REFO_128KHZ); //CS_REFO_128KHZ);
    MAP_CS_initClockSignal(CS_ACLK, CS_REFOCLK_SELECT, CS_CLOCK_DIVIDER_128);

    /* Configuring P1.0 as output */
    MAP_GPIO_setAsOutputPin(GPIO_PORT_P1, GPIO_PIN0);
    MAP_GPIO_setOutputLowOnPin(GPIO_PORT_P1, GPIO_PIN0);

    /* Configuring Timer_A1 for Up Mode */
    MAP_Timer_A_configureUpMode(TIMER_A1_BASE, &upConfig);

    /* Enabling interrupts and starting the timer */
    // MAP_Interrupt_enableSleepOnIsrExit();
    MAP_Interrupt_enableInterrupt(INT_TA1_0);
    MAP_Timer_A_startCounter(TIMER_A1_BASE, TIMER_A_UP_MODE);

    /* Enabling MASTER interrupts */
    MAP_Interrupt_enableMaster();

    /* Sleeping when not in use */
    while (1)
    {
        if (STATE2 == TIMER_MSG_REC) {
            printf("THE TIMER MESSAGE WAS RECEIVED FROM THE INTERRUPT\n");
            STATE2 = MSG_WAIT;
        }
        // MAP_PCM_gotoLPM0();
    }
}

void TA1_0_IRQHandler(void)
{
    STATE2 = TIMER_MSG_REC;
    // printf("interrupt count: %d\n", ++interruptCount);
    MAP_GPIO_toggleOutputOnPin(GPIO_PORT_P1, GPIO_PIN0);
    MAP_Timer_A_clearCaptureCompareInterrupt(TIMER_A1_BASE,
            TIMER_A_CAPTURECOMPARE_REGISTER_0);
}
