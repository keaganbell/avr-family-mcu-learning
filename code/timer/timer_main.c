#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

#include "led.c"
#include "timer.c"

// one second blink time
#define BLINK_TIME_MS 1000

int main(void) {
    // initialize blink timer
    uint32_t last_blink_time = 0;
    
    // initialization
    led_init();
    timer_init();
    
    // enable interrupts
    sei();
    
    // main loop
    for (;;) {
        uint32_t current_time;
        current_time = timer_get_ms();
        if (current_time - last_blink_time >= BLINK_TIME_MS) {
            led_toggle();
            last_blink_time = current_time;
        }
    }
    
    return 0;
}