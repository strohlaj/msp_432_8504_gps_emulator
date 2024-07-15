////#include <Timer/AJS_Timer.h>
////#include <Timer/AJS_Timer.h>
//#include "msp.h"
//#include "stdbool.h"
//#include "stdio.h"
//#include "stdint.h"
//#include "driverlib.h"
//
//const Timer_A_ContinuousModeConfig continuousModeConfig =
//{
//        TIMER_A_CLOCKSOURCE_ACLK,           // ACLK Clock Source
//        TIMER_A_CLOCKSOURCE_DIVIDER_1,      // ACLK/1 = 32.768khz
//        TIMER_A_TAIE_INTERRUPT_ENABLE,      // Enable Overflow ISR
//        TIMER_A_DO_CLEAR                    // Clear Counter
//};
//
//const Timer_A_UpModeConfig upModeConfig =
//{
//     TIMER_A_CLOCKSOURCE_ACLK,
//     TIMER_A_CLOCKSOURCE_DIVIDER_1,
//     10000,
//     TIMER_A_TAIE_INTERRUPT_DISABLE,
//     TIMER_A_CCIE_CCR0_INTERRUPT_DISABLE,
//     TIMER_A_SKIP_CLEAR
//};
//
//const Timer_A_CompareModeConfig compareModeConfig2k =
//{
//    TIMER_A_CAPTURECOMPARE_REGISTER_1,
//    TIMER_A_CAPTURECOMPARE_INTERRUPT_ENABLE,
//    TIMER_A_OUTPUTMODE_SET,
//    2000
//};
//
//// TIMER_A_TAIE_INTERRUPT_ENABLE,
//const Timer_A_CompareModeConfig compareModeConfig5k =
//{
//    TIMER_A_CAPTURECOMPARE_REGISTER_2,
//    TIMER_A_CAPTURECOMPARE_INTERRUPT_ENABLE,
//    TIMER_A_OUTPUTMODE_SET_RESET,
//    5000
//};
//
//// #define FULL_NAME_START 0x0003F000
//// #define FULL_NAME_START 0x0003F500
//// #define FULL_NAME_START 0x00030000
//// #define FULL_NAME_START 0x0002F000
//// #define FULL_NAME_START    0x00020500
///**
// * main.c
// */
//typedef enum _APP_STATE {
//    TIMER_STOPPED,
//    TIMER_STARTED,
//} APP_STATE;
//
//APP_STATE STATE = TIMER_STOPPED;
//static int interruptCounter = 0;
//
//void timer_a_ccrx_isr(void) {
//
//    MAP_Timer_A_clearInterruptFlag(TIMER_A0_BASE);
//    if (MAP_Timer_A_getCaptureCompareInterruptStatus(TIMER_A0_BASE,
//                                                     TIMER_A_CAPTURECOMPARE_REGISTER_1,
//                                                     TIMER_A_CAPTURECOMPARE_INTERRUPT_FLAG)) {
//        MAP_Timer_A_clearCaptureCompareInterrupt(TIMER_A0_BASE, TIMER_A_CAPTURECOMPARE_REGISTER_1);
//    } else if (MAP_Timer_A_getCaptureCompareInterruptStatus(TIMER_A0_BASE,
//                                                            TIMER_A_CAPTURECOMPARE_REGISTER_2,
//                                                            TIMER_A_CAPTURECOMPARE_INTERRUPT_FLAG)) {
//        MAP_Timer_A_clearCaptureCompareInterrupt(TIMER_A0_BASE, TIMER_A_CAPTURECOMPARE_REGISTER_2);
//
//    } else {
//        MAP_Timer_A_clearCaptureCompareInterrupt(TIMER_A0_BASE, TIMER_A_CAPTURECOMPARE_REGISTER_0);
//    }
//
////    interruptCounter++;
////    if (interruptCounter % 2 == 0) {
////        MAP_GPIO_toggleOutputOnPin(GPIO_PORT_P1, GPIO_PIN0);
////    } else {
////        MAP_GPIO_toggleOutputOnPin(GPIO_PORT_P2, GPIO_PIN1);
////        MAP_GPIO_toggleOutputOnPin(GPIO_PORT_P2, GPIO_PIN2);
////    }
//}
//
//void timer_a_ccr0_isr(void) {
//    MAP_Timer_A_clearCaptureCompareInterrupt(TIMER_A0_BASE, TIMER_A_CAPTURECOMPARE_REGISTER_0);
//    MAP_Timer_A_clearInterruptFlag(TIMER_A0_BASE);
//    Timer_A_Type* tmr = TIMER_A_CMSIS(TIMER_A0_BASE);
//    uint16_t ccr0 = TIMER_A_CMSIS(TIMER_A0_BASE)->CCR[0];
//    uint16_t ccr1 = TIMER_A_CMSIS(TIMER_A0_BASE)->CCR[1];
//    uint16_t ccr2 = TIMER_A_CMSIS(TIMER_A0_BASE)->CCR[2];
//    uint16_t ccr3 = TIMER_A_CMSIS(TIMER_A0_BASE)->CCR[3];
//    uint16_t ccr4 = TIMER_A_CMSIS(TIMER_A0_BASE)->CCR[4];
//}
//
//void main3(void)
//{
//    // TIMER_A_TAIE_INTERRUPT_ENABLE
//
//    const char full_name[] = "aaron strohl alskjdflkasjdf lkasjdf lkasjdf lkjsfaoies jlk dlaksjfaieojflksdfj asoi jalsdfkj laskdfj aesoijf aslkdfjaoiejf lksdfsd";
//
//    /* Stop watchdog timer */
//    MAP_WDT_A_holdTimer();
//
//    /* Configuring P1.0 as output */
//    MAP_GPIO_setAsOutputPin(GPIO_PORT_P1, GPIO_PIN0);
//    MAP_GPIO_setOutputLowOnPin(GPIO_PORT_P1, GPIO_PIN0);
//
//
//    MAP_GPIO_setAsOutputPin(GPIO_PORT_P2, GPIO_PIN1);
//    MAP_GPIO_setAsOutputPin(GPIO_PORT_P2, GPIO_PIN2);
//    MAP_GPIO_setOutputLowOnPin(GPIO_PORT_P2, GPIO_PIN1);
//    MAP_GPIO_setOutputLowOnPin(GPIO_PORT_P2, GPIO_PIN2);
//
//    // void (*intHandler)(void)
//
////    MAP_GPIO_setAsPeripheralModuleFunctionOutputPin(GPIO_PORT_P7,
////            GPIO_PIN6 + GPIO_PIN7, GPIO_PRIMARY_MODULE_FUNCTION);
//
////      MAP_GPIO_setAsPeripheralModuleFunctionOutputPin(GPIO_PORT_P1,
////               GPIO_PIN0, GPIO_PRIMARY_MODULE_FUNCTION);
//
//    MAP_CS_setReferenceOscillatorFrequency(CS_REFO_128KHZ);
//    MAP_CS_initClockSignal(CS_ACLK, CS_REFOCLK_SELECT, CS_CLOCK_DIVIDER_128);
//
////    FlashCtl_setWaitState(FLASH_BANK0, 2);
////    FlashCtl_setWaitState(FLASH_BANK1, 2);
////
////    MAP_FlashCtl_unprotectSector(FLASH_MAIN_MEMORY_SPACE_BANK1, FLASH_SECTOR16);
////
////    uint8_t res = MAP_FlashCtl_programMemory((void*) full_name, (void*) FULL_NAME_START, 55);
////
////    MAP_FlashCtl_protectSector(FLASH_MAIN_MEMORY_SPACE_BANK1, FLASH_SECTOR21);
//
//    /* Configuring Continuous Mode */
//    // MAP_Timer_A_configureContinuousMode(TIMER_A0_BASE, &continuousModeConfig);
//    MAP_Timer_A_configureUpMode(TIMER_A0_BASE, &upModeConfig);
//
//    MAP_Timer_A_initCompare(TIMER_A0_BASE, &compareModeConfig2k);
//    MAP_Timer_A_initCompare(TIMER_A0_BASE, &compareModeConfig5k);
//    /* Enabling interrupts and going to sleep */
//    // MAP_Interrupt_enableSleepOnIsrExit();
//    // MAP_Interrupt_enableInterrupt(INT_TA0_0);
//    MAP_Timer_A_enableInterrupt(TIMER_A0_BASE);
//    MAP_Timer_A_enableCaptureCompareInterrupt(TIMER_A0_BASE, TIMER_A_CAPTURECOMPARE_REGISTER_0);
//    MAP_Timer_A_enableCaptureCompareInterrupt(TIMER_A0_BASE, TIMER_A_CAPTURECOMPARE_REGISTER_1);
//
//    MAP_Timer_A_registerInterrupt(TIMER_A0_BASE, TIMER_A_CCRX_AND_OVERFLOW_INTERRUPT, timer_a_ccrx_isr);
//    MAP_Timer_A_registerInterrupt(TIMER_A0_BASE, TIMER_A_CCR0_INTERRUPT, timer_a_ccr0_isr);
//
//    /* Enabling MASTER interrupts */
//    MAP_Interrupt_enableMaster();
//
//    /* Starting the Timer_A0 in continuous mode */
//    // MAP_Timer_A_startCounter(TIMER_A0_BASE, TIMER_A_CONTINUOUS_MODE);
//
//
////    uint32_t interruptStatus = MAP_Timer_A_getEnabledInterruptStatus(TIMER_A0_BASE);
////    printf("timer interrupt status: %d\n", interruptStatus);
////
////    uint32_t captureCompareEnabled = Timer_A_getCaptureCompareEnabledInterruptStatus(TIMER_A0_BASE, TIMER_A_CAPTURECOMPARE_REGISTER_0);
////    printf("capture Compare Enabled status %d\n", captureCompareEnabled);
//
//    while(1)
//    {
//        if (STATE == TIMER_STOPPED) {
//            printf("%s", "Started timer");
//            STATE = TIMER_STARTED;
//            MAP_Timer_A_startCounter(TIMER_A0_BASE, TIMER_A_UP_MODE);
//        }
//        static int count = 0;
//        count++;
//        if (count % 200 == 0) {
//            uint16_t counterVal = MAP_Timer_A_getCounterValue(TIMER_A0_BASE);
//            printf("counterval %d\n", counterVal);
//        }
//        if (interruptCounter > 25) {
//            MAP_GPIO_setOutputLowOnPin(GPIO_PORT_P1, GPIO_PIN0);
//            MAP_GPIO_setOutputLowOnPin(GPIO_PORT_P2, GPIO_PIN1);
//            MAP_GPIO_setOutputLowOnPin(GPIO_PORT_P2, GPIO_PIN2);
//            MAP_Timer_A_stopTimer(TIMER_A0_BASE);
//            MAP_Timer_A_clearTimer(TIMER_A0_BASE);
//        }
//    }
//}
//
//void TA0_0_IRQHandler(void) {
//    MAP_Timer_A_clearCaptureCompareInterrupt(TIMER_A0_BASE, TIMER_A_CAPTURECOMPARE_REGISTER_0);
//    interruptCounter++;
//    if (interruptCounter % 2 == 0) {
//        MAP_GPIO_toggleOutputOnPin(GPIO_PORT_P1, GPIO_PIN0);
//    } else {
//        MAP_GPIO_toggleOutputOnPin(GPIO_PORT_P2, GPIO_PIN1);
//        MAP_GPIO_toggleOutputOnPin(GPIO_PORT_P2, GPIO_PIN2);
//    }
//}
//
//void TA0_N_IRQHandler(void) {
//
//    uint32_t captureCompareEnabled = Timer_A_getCaptureCompareEnabledInterruptStatus(TIMER_A0_BASE, TIMER_A_CAPTURECOMPARE_REGISTER_0);
//    uint32_t interruptStatus = MAP_Timer_A_getEnabledInterruptStatus(TIMER_A0_BASE);
//
//    // MAP_Timer_A_clearCaptureCompareInterrupt(TIMER_A0_BASE, TIMER_A_CAPTURECOMPARE_REGISTER_0);
//    MAP_Timer_A_clearInterruptFlag(TIMER_A0_BASE);
//
//
////    MAP_Timer_A_disableInterrupt(TIMER_A0_BASE);
////    MAP_Timer_A_clearTimer(TIMER_A0_BASE);
//
//   //  MAP_Timer_A_stopTimer(TIMER_A0_BASE);
//    // STATE = TIMER_STOPPED;
//
////    __no_operation();
////    __no_operation();
////    __no_operation();
////    __no_operation();
////    __no_operation();
////    __no_operation();
////    __no_operation();
////    __no_operation();
//
//
//    // interruptStatus = MAP_Timer_A_getEnabledInterruptStatus(TIMER_A0_BASE);
//    // static int toggle = 0;
//    // uint16_t counterVal = MAP_Timer_A_getCounterValue(TIMER_A0_BASE);
////    if (toggle == 0 || toggle % 100 == 0) {
////
////        printf("interrupt counter value %d\n", counterVal);
////    }
//    // toggle++;
//
//
//   // MAP_Timer_A_clearInterruptFlag(TIMER_A0_BASE);
////    uint32_t enabledInterruptStatus =
////            MAP_Timer_A_getCaptureCompareEnabledInterruptStatus(TIMER_A0_BASE,TIMER_A_CAPTURECOMPARE_REGISTER_0);
//
//    // if (enabledInterruptStatus & TIMER_A_CAPTURECOMPARE_INTERRUPT_FLAG) {
////        MAP_Timer_A_clearCaptureCompareInterrupt(TIMER_A0_BASE, TIMER_A_CAPTURECOMPARE_REGISTER_0);
////        MAP_Timer_A_clearCaptureCompareInterrupt(TIMER_A0_BASE, TIMER_A_CAPTURECOMPARE_REGISTER_1);
////        MAP_Timer_A_clearCaptureCompareInterrupt(TIMER_A0_BASE, TIMER_A_CAPTURECOMPARE_REGISTER_2);
////        MAP_Timer_A_clearCaptureCompareInterrupt(TIMER_A0_BASE, TIMER_A_CAPTURECOMPARE_REGISTER_3);
////        MAP_Timer_A_clearCaptureCompareInterrupt(TIMER_A0_BASE, TIMER_A_CAPTURECOMPARE_REGISTER_4);
////        MAP_Timer_A_clearCaptureCompareInterrupt(TIMER_A0_BASE, TIMER_A_CAPTURECOMPARE_REGISTER_5);
////        MAP_Timer_A_clearCaptureCompareInterrupt(TIMER_A0_BASE, TIMER_A_CAPTURECOMPARE_REGISTER_6);
//    // }
//
//
////    if (MAP_Timer_A_getEnabledInterruptStatus(TIMER_A0_BASE) == TIMER_A_INTERRUPT_PENDING) {
////        MAP_Timer_A_clearInterruptFlag(TIMER_A0_BASE);
////    }
//
//
//    // MAP_Timer_A_enableInterrupt(TIMER_A0_BASE);
//    // MAP_Timer_A_stopCounter(TIMER_A0_BASE, TIMER_A_UP_MODE);
//    //uint16_t gpioPin = toggle % 2 == 0 ? GPIO_PIN0 : GPIO_PIN1;
//    // MAP_GPIO_toggleOutputOnPin(GPIO_PORT_P1, GPIO_PIN0);
//}
//
