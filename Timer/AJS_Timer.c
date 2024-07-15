/*
 * Timer.c
 *
 *  Created on: Sep 7, 2021
 *      Author: AaronStrohl
 */

//#include <Timer/AJS_Timer.h>
//
//bool state = false;
//
//void timer_init(void)
//{
//    Timer_A_ContinuousModeConfig initConfig = {0};
//    initConfig.clockSource = TIMER_A_CLOCKSOURCE_ACLK;
//    initConfig.clockSourceDivider = TIMER_A_CLOCKSOURCE_DIVIDER_1;
//    initConfig.timerInterruptEnable_TAIE =  TIMER_A_TAIE_INTERRUPT_ENABLE;
//    initConfig.timerClear = TIMER_A_DO_CLEAR;
//    Timer_A_initContinuousMode(TIMER_A0_BASE, &initConfig);
//    Timer_A_enableInterrupt(TIMER_A0_BASE);
//    // Timer_A_registerInterrupt(TIMER_A0_BASE, TIMER_A_CCR0_INTERRUPT, (*Timer_A_ISR));
//    Timer_A_startCounter(TIMER_A0_BASE, TIMER_A_CONTINUOUS_MODE);
//}
//
//
//void TA0_0_IRQHandler(void)
//{
//    state = !state;
//}
//
//bool toggle(void)
//{
//    state = !state;
//    return state;
//}

