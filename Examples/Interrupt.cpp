#include <Arduino.h>

ISR (INT0_vect) {
    PORTD ^= 0b01000000;
}

ISR (INT1_vect) {
    PORTD ^= 0b10000000;
}

int main(void) {

    DDRD = 0b11000000;
    PORTD = 0b00001100;

    EICRA = 0b00000101;
    EIMSK = 0b00000011;
    sei();

    while(1) {
        _delay_ms(5000);
    }
}