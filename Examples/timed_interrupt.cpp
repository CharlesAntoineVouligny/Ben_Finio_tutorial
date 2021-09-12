#include <Arduino.h>

// Timer/Counter1 Compare Match A
ISR(TIMER1_COMPA_vect) {
    // Toggle LEDs
    PORTD ^= 0b10000000;
    PORTB ^= 0b00100000;
}

int main(void) {
    // Set internal LED as output
    DDRD = 0b10000000; // Set pin 7 to OUTPUT
    DDRB = 0b00100000; // Set internal LED to OUTPUT
    
    //Normal timer mode
    //TCCR1A = 0b00000000; 
    TCCR1B = 0b00001101; // CTC mode enabled WGM12 (xxxx1xxx)  and prescaler set to 1024bits (xxxxx101)

    // Set timer limit (OCR1A/B + 1) * prescaler * 62.5 nanoSeconds
    //(15624 + 1) * 1024 * 62.5 x10^-9 = 1 second
    OCR1A = 15624; // Clear Timer on Compare mode(CTC) maximum value 
    TIMSK1 = 0B00000010; // Set OCIEA bit true to enable compare with OCR1A 
    // Output compare A match interrupt enable
    sei(); //enable interrupts globally

    while(1) {

    }

}
