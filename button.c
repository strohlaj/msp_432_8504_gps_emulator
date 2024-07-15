#include "button.h"


void init_buttons(void) {
    MAP_GPIO_setAsInputPinWithPullUpResistor(GPIO_PORT_P1, GPIO_PIN1);
    MAP_GPIO_clearInterruptFlag(GPIO_PORT_P1, GPIO_PIN1);
    enable_button();
    MAP_Interrupt_enableInterrupt(INT_PORT1);
}

void enable_button(void) {
    MAP_GPIO_enableInterrupt(GPIO_PORT_P1, GPIO_PIN1);
}

void disable_button(void) {
    MAP_GPIO_disableInterrupt(GPIO_PORT_P1, GPIO_PIN1);
}

void PORT1_IRQHandler(void) {
    uint_fast16_t status = MAP_GPIO_getEnabledInterruptStatus(GPIO_PORT_P1);

    MAP_GPIO_clearInterruptFlag(GPIO_PORT_P1, status);

    disable_button();

    queue_item keepAliveEvent = { .eventId = BUTTON_PRESSED };

    enqueue(keepAliveEvent);
}

