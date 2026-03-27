#include <avr/io.h>
#include <avr/interrupt.h>

#include "base_core.h"

#include "led.c"
#include "timer.c"
#include "pwm.c"
#include "button.c"

int main(void) {
    uint8_t brightness = 0;
    uint32_t last_pulse_time = 0;
    uint32_t last_press_time = 0;
    uint32_t pulse_elapsed = 0;
    bool invert = false;
    bool blink = true, was_blinking_last_tick = true;
    
    // initialization
    pwm_init();
    led_init();
    button_init();
    timer_init();
    
    // enable interrupts
    sei();
    
    // main loop
    led_toggle();
    for (;;) {
        uint32_t t;
        uint32_t current_time;
        
        current_time = timer_get_ms();
        
        if (current_time - last_press_time >= BUTTON_LATENCY_MS) {
            button_update();
            if (button_pressed()) {
                blink = !blink;
            }
            last_press_time = current_time;
        }
        
        
        if (blink) {
            if (!was_blinking_last_tick) {
                last_pulse_time =  current_time - pulse_elapsed;
                was_blinking_last_tick = true;
            } else {
                pulse_elapsed = current_time - last_pulse_time;
            }
            
            t = (255*pulse_elapsed)/LED_PULSE_TIME_MS;
            t = invert ? 255 - t : t;
            brightness = (uint8_t)CLAMP(t, 0, 255);
            
        } else {
            was_blinking_last_tick = false;
        }
        
        if (pulse_elapsed >= LED_PULSE_TIME_MS) {
            invert = !invert;
            last_pulse_time = current_time;
        }
        
        pwm_led_emit(brightness);
    }
    
    return 0;
}