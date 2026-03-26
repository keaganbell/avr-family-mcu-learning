#include <avr/io.h>
#include <avr/interrupt.h>

#include "base_core.h"

#include "led.c"
#include "timer.c"
#include "pwm.c"

#define LED_PULSE_TIME_MS 1000

int main(void) {
    uint8_t brightness = 0;
    uint32_t last_pulse_time = 0;
    bool invert = false;
    
    // initialization
    pwm_init();
    led_init();
    timer_init();
    
    // enable interrupts
    sei();
    
    // main loop
    led_toggle();
    for (;;) {
        uint32_t t, elapsed;
        uint32_t current_time;
        
        current_time = timer_get_ms();
        elapsed = current_time - last_pulse_time;
        t = (255*elapsed)/LED_PULSE_TIME_MS;
        t = invert ? 255 - t : t;
        brightness = (uint8_t)CLAMP(t, 0, 255);
        
        if (elapsed >= LED_PULSE_TIME_MS) {
            invert = !invert;
            last_pulse_time = current_time;
        }
        
        pwm_led_emit(brightness);
    }
    
    return 0;
}