#include <Arduino.h>
int main (void) {
  // setup code that only runs once

  // DDRD is Direction Directory D, it set the pins as OUTPUTS (1)
  // default is INPUT (0)
  DDRD = 0b10110100;

  // This bitwise operation shift the first bit 2 places
  PORTD = 1 << 2;

  while(1){
  // code that loops forever

// First set pin 4 and 5  HIGH
  PORTD = PORTD | 1 << 4;
  PORTD = PORTD | 1 << 5;
  _delay_ms(500);

  // Set pin 5 low after 500ms, keep 4 HIGH (unchanged)
  PORTD = PORTD & 0b11011111;
  _delay_ms(500);

  // After 1000ms, set 5 HIGH and 4 LOW
  PORTD = PORTD ^ 0b00110000;
  _delay_ms(500);

  // Set both pins LOW after 1500ms but keep pin 2 HIGH
  PORTD = PORTD & 0b00000100;
  _delay_ms(500);



  }
}