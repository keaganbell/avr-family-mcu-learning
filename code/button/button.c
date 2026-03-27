
#define BUTTON_LATENCY_MS 5

static bool button_released_this_tick;
static uint32_t button_down_counter;

static void button_init() {
    // set pin 7 to input mode
    DDRD &= ~(1<<DDD7);
    
    // set pin 7 to pull up and active low
    // when the button is pressed, 
    // the pin is directed to ground
    PORTD |= (1<<PORTD7);
}

static bool button_is_down() {
    return button_down_counter > 0;
}

static bool button_pressed() {
    return button_down_counter == 1;
}

static bool button_released() {
    return button_released_this_tick;
}

static void button_update() {
    if (!(PIND & (1<<PIND7))) {
        button_down_counter += 1;
    } else if (button_down_counter > 0) {
        // released this frame
        button_released_this_tick = true;
        button_down_counter = 0;
    } else {
        button_released_this_tick = false;
    }
}