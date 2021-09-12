#include <Arduino.h>

ISR(PCINT0_vect) {
    PORTB ^= 0b00000001;
}

int main(void) {
    DDRB = 0b00000001;
    PORTB = 0b00000111;

    PCICR = 0b00000001;
    PCMSK0 = 0b00000110;
    sei();

    while(1) {
        _delay_ms(5000);
    }
}