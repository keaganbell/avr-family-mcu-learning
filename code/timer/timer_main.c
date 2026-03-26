#include <avr/io.h>
#include <util/delay.h>

#include "base_core.h"

int main(void) {
    
    DDRB |= (1<<DDB5);
    
    for (;;) {
        PORTB ^= (1<<PORTB5);
        _delay_ms(1000);
    }
    
    return 0;
}