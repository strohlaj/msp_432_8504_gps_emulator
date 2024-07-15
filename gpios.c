#include "gpios.h"

void init_gpios(void) {
    // RED Channel LED 1
    MAP_GPIO_setAsOutputPin(GPIO_PORT_P1, GPIO_PIN0);

    MAP_GPIO_setOutputHighOnPin(GPIO_PORT_P1, GPIO_PIN0);
    MAP_GPIO_setOutputLowOnPin(GPIO_PORT_P1, GPIO_PIN0);

    // RED Channel LED 2
    MAP_GPIO_setAsOutputPin(GPIO_PORT_P2, GPIO_PIN0);

    MAP_GPIO_setOutputHighOnPin(GPIO_PORT_P2, GPIO_PIN0);
    MAP_GPIO_setOutputLowOnPin(GPIO_PORT_P2, GPIO_PIN0);

    // GREEN Channel of LED 2
    MAP_GPIO_setAsOutputPin(GPIO_PORT_P2, GPIO_PIN1);

    MAP_GPIO_setOutputHighOnPin(GPIO_PORT_P2, GPIO_PIN1);
    // MAP_GPIO_setOutputLowOnPin(GPIO_PORT_P2, GPIO_PIN1);

    // BLUE Channel of LED 2 -- KEEP ALIVE LED
    MAP_GPIO_setAsOutputPin(GPIO_PORT_P2, GPIO_PIN2);

    MAP_GPIO_setOutputHighOnPin(GPIO_PORT_P2, GPIO_PIN2);
    MAP_GPIO_setOutputLowOnPin(GPIO_PORT_P2, GPIO_PIN2);

    // MAP_GPIO_setOutputLowOnPin(GPIO_PORT_P1, GPIO_PIN0);
}

void toggle_keep_alive_led(void) {
    GPIO_toggleOutputOnPin(GPIO_PORT_P2, GPIO_PIN2);
}

void turn_off_time_marked_pulse(void) {

}

void turn_on_time_marked_pulse(void) {

}
