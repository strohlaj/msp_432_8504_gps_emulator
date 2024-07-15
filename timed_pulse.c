#include "timed_pulse.h"


//const Timer_A_ContinuousModeConfig continuousModeConfig =
//{
//        TIMER_A_CLOCKSOURCE_ACLK,           // ACLK Clock Source
//        TIMER_A_CLOCKSOURCE_DIVIDER_1,      // ACLK/1 = 32.768khz
//        TIMER_A_TAIE_INTERRUPT_ENABLE,      // Enable Overflow ISR
//        TIMER_A_DO_CLEAR                    // Clear Counter
//};

const Timer_A_UpModeConfig upModeConfig =
{
     TIMER_A_CLOCKSOURCE_ACLK,
     TIMER_A_CLOCKSOURCE_DIVIDER_1,
     1000,
     TIMER_A_TAIE_INTERRUPT_DISABLE,
     TIMER_A_CCIE_CCR0_INTERRUPT_ENABLE,
     // TIMER_A_CCIE_CCR0_INTERRUPT_DISABLE,
     TIMER_A_DO_CLEAR
};

//const Timer_A_CompareModeConfig compareModeConfig1k =
//{
//    TIMER_A_CAPTURECOMPARE_REGISTER_2,
//    TIMER_A_CAPTURECOMPARE_INTERRUPT_ENABLE,
//    TIMER_A_OUTPUTMODE_SET,
//    1000
//};

// TIMER_A_TAIE_INTERRUPT_ENABLE,
const Timer_A_CompareModeConfig compareModeConfig200ms =
{
    TIMER_A_CAPTURECOMPARE_REGISTER_1,
    TIMER_A_CAPTURECOMPARE_INTERRUPT_ENABLE,
    TIMER_A_OUTPUTMODE_SET_RESET,
    200 // ms
};


static void timer_a_ccrx_isr(void);

// Timer A is configured at a 1khz clock to count up to 1,000. Rollover will occur approximately every 1 second.
// Every 1 seconds, CCRX overflow fires an ISR for Keep alive LED
// `Oneshot` 200ms gps time marked pulse interrupt
void init_timer_a(void) {
    MAP_Timer_A_configureUpMode(TIMER_A0_BASE, &upModeConfig);

    // MAP_Timer_A_initCompare(TIMER_A0_BASE, &compareModeConfig1k);

    MAP_Timer_A_enableInterrupt(TIMER_A0_BASE);

    // Registers the timer_a_ccrx_isr function pointer to the timer a capture compare register overflow interrupt
    MAP_Timer_A_registerInterrupt(TIMER_A0_BASE, TIMER_A_CCRX_AND_OVERFLOW_INTERRUPT, timer_a_ccrx_isr);
}

void start_gps_time_marked_pulse(void) {
    // MAP_GPIO_setOutputLowOnPin(GPIO_PORT_P2, GPIO_PIN1);
    turn_on_time_marked_pulse();

    // Stop timer, disable interrupts
    MAP_Timer_A_disableInterrupt(TIMER_A0_BASE);
    MAP_Timer_A_stopTimer(TIMER_A0_BASE);
    MAP_Timer_A_disableCaptureCompareInterrupt(TIMER_A0_BASE, TIMER_A_CAPTURECOMPARE_REGISTER_1);

    // Reconfigure timer with 200ms one-shot interrupt on register 1
    MAP_Timer_A_configureUpMode(TIMER_A0_BASE, &upModeConfig);
    MAP_Timer_A_clearCaptureCompareInterrupt(TIMER_A0_BASE, TIMER_A_CAPTURECOMPARE_REGISTER_1);
    MAP_Timer_A_initCompare(TIMER_A0_BASE, &compareModeConfig200ms);
    MAP_Timer_A_startCounter(TIMER_A0_BASE, TIMER_A_UP_MODE);
    MAP_Timer_A_enableCaptureCompareInterrupt(TIMER_A0_BASE, TIMER_A_CAPTURECOMPARE_REGISTER_1);
    MAP_Timer_A_enableInterrupt(TIMER_A0_BASE);
}


void timer_a_ccrx_isr(void) {

    MAP_Timer_A_clearInterruptFlag(TIMER_A0_BASE);
//    if (MAP_Timer_A_getCaptureCompareInterruptStatus(TIMER_A0_BASE,
//                                                     TIMER_A_CAPTURECOMPARE_REGISTER_2,
//                                                     TIMER_A_CAPTURECOMPARE_INTERRUPT_FLAG)) {
//
//        MAP_Timer_A_clearCaptureCompareInterrupt(TIMER_A0_BASE, TIMER_A_CAPTURECOMPARE_REGISTER_2);
//
//
//    } else
    if (MAP_Timer_A_getCaptureCompareInterruptStatus(TIMER_A0_BASE,
                                                     TIMER_A_CAPTURECOMPARE_REGISTER_0,
                                                     TIMER_A_CAPTURECOMPARE_INTERRUPT_FLAG)) {
        MAP_Timer_A_clearCaptureCompareInterrupt(TIMER_A0_BASE, TIMER_A_CAPTURECOMPARE_REGISTER_0);
        queue_item keepAliveEvent = {.eventId = KEEP_ALIVE_LED};
        enqueue(keepAliveEvent);

    } else if (MAP_Timer_A_getCaptureCompareInterruptStatus(TIMER_A0_BASE,
                                                     TIMER_A_CAPTURECOMPARE_REGISTER_1,
                                                     TIMER_A_CAPTURECOMPARE_INTERRUPT_FLAG)) {
        // Clear Interrupt
        MAP_Timer_A_clearCaptureCompareInterrupt(TIMER_A0_BASE, TIMER_A_CAPTURECOMPARE_REGISTER_1);

        // Disable this single-shot capture compare
        MAP_Timer_A_disableCaptureCompareInterrupt(TIMER_A0_BASE, TIMER_A_CAPTURECOMPARE_REGISTER_1);
        // Disable Uart data Xfer light
        MAP_GPIO_setOutputLowOnPin(GPIO_PORT_P2, GPIO_PIN1);

        turn_off_time_marked_pulse();

        queue_item tmmCompleteEvent = {.eventId = TIME_MARKED_PULSE_COMPLETE};
        enqueue(tmmCompleteEvent);
        // enable the button back after 200ms
        enable_button();

    }
}

