#include <Arduino.h>

int main(void){

     // Counts in normal timer mode (TCCR1A), prescaler is set to 1024bits (TCCR1B)
    // p.140 http://ww1.microchip.com/downloads/en/DeviceDoc/ATmega48A-PA-88A-PA-168A-PA-328-P-DS-DS40002061A.pdf
    Serial.begin(9600);
    TCCR1A = 0b000000000;
    TCCR1B = 0b000000101;


    while(1){
        Serial.println(TCNT1);
    }
}