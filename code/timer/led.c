
static void led_init(void) {
    // initialize PORTB for output on pin 3 (gpio ~11)
    DDRB |= (1<<DDB3);
}

static void led_toggle(void) {
    // toggle PORTB3 on and off
    PORTB ^= (1<<PORTB3);
}