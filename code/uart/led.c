
static void led_init(void) {
    DDRB |= (1<<DDB3);
}

static void led_toggle(void) {
    PORTB ^= (1<<PORTB3);
}