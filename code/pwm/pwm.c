
static void pwm_init(void) {
    // Datasheet section 15.11
    
    // TCCR1A:
    // COM1A1 COM1A0 COM1B1 COM1B0 - - WGM11 WGM10
    //    7      6      5      4   3 2   1     0
    
    // TCCR1B:
    // ICNC1 ICES1 - WGM13 WGM12 CS12 CS11 CS10
    //   7     6   5   4     3    2    1    0
    
    // 1. NON-inverting mode
    // Fast PWM: COM1A1/COM1B1:1, COM1A0/COM1B0:0
    TCCR1A |=  (1<<COM1A1);
    TCCR1A &= ~(1<<COM1A0);
    
    // 2. Waveform Generation
    // Fast PWM 8-bit: Mode 5, WGM13:0, WGM12:1, WGM11:0, WGM10:1
    TCCR1B &= ~(1<<WGM13);
    TCCR1B |=  (1<<WGM12);
    TCCR1A &= ~(1<<WGM11);
    TCCR1A |=  (1<<WGM10);
    
    // 3. Prescaler
    // Prescaler set to 8: CS12:0 CS11:1 CS10:0
    TCCR1B &= ~(1<<CS12);
    TCCR1B |=  (1<<CS11);
    TCCR1B &= ~(1<<CS10);
}

static void pwm_led_emit(uint8_t brightness) {
    OCR1A = brightness;
}