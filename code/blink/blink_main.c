#include <avr/io.h>
#include <util/delay.h>

int main(void) {
    DDRB = DDRB | (1<<DDB5);
    for (;;) {
        PORTB = PORTB | (1<<PORTB5);
        _delay_ms(500);
        PORTB = PORTB & ~(1<<PORTB5);
        _delay_ms(500);
    }
    return 0;
}