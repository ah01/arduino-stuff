/*
 * Based on IRsendDemo from IRremote libriray
 * An IR LED must be connected to Arduino PWM pin 3.
 * 
 * IRremote (https://github.com/shirriff/Arduino-IRremote)
 */

#include <IRremote.h>

IRsend irsend;

#define COMANDS 24

/*
    Code of all buttons of IR remote control.    
*/
unsigned long codes[COMANDS] = {
    0xF700FF,
    0xF7807F,
    0xF740BF,
    0xF7C03F,
    0xF720DF,
    0xF7A05F,
    0xF7609F,
    0xF7E01F,
    0xF710EF,
    0xF7906F,
    0xF750AF,
    0xF7D02F,
    0xF730CF,
    0xF7B04F,
    0xF7708F,
    0xF7F00F,
    0xF708F7,
    0xF78877,
    0xF748B7,
    0xF7C837,
    0xF728D7,
    0xF7A857,
    0xF76897,
    0xF7E817
};

void setup()
{
    Serial.begin(9600);
    Serial.println("INIT done");
}

void loop() {

    int n = Serial.parseInt();

    if (n == 0) return; // timeout

    if (n < 1 || n > COMANDS)
    {
        Serial.println("Err");
        return;
    }

    unsigned long code = codes[n - 1];

    Serial.print("Code n: ");
    Serial.println(n, DEC);
  
    irsend.sendNEC(code, 32);
}

