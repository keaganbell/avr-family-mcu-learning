//#define F_CPU 16000000UL
//#define BAUD 9600
//#include <util/setbaud.h>

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

#include "base_core.h"

#include "led.c"
#include "timer.c"

static uint32_t last_time;

int main(void) {
    
    // initialization
    led_init();
    timer_init();
    
    // enable interrupts
    sei();    
    
    // main loop
    for (;;) {
        uint32_t current_time;
        
        current_time = timer_get_ms();
        
        if (current_time - last_time >= 1000) {
            led_toggle();
            last_time = current_time;
        }
    }
    
    return 0;
}