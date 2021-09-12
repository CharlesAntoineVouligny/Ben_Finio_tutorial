#include <Arduino.h>
int main (void) {
  // setup code that only runs once

  // DDRD is Direction Directory D, it set the pins as OUTPUTS (1)
  // default is INPUT (0)

  // Set Pins 2 and 4 as OUTPUTS
  DDRD = 0b00010100;

  // Turn the intern pullup active for the button input pins
  // 6 and 7
  PORTD = 0b11000000;

  while(1){
  // code that loops forever

  // 
    if (PIND & 0b10000000) {
      PORTD &= 0b11101111;
    } else {
      PORTD |= 0b00010000;
    }
    if (PIND & 0b01000000) {
      PORTD &= 0b11111011;
    } else {
      PORTD |= 0b00000100;
    }



  }
}