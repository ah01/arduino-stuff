#include <Bridge.h>

#define LED_R 5
#define LED_G 3
#define LED_B 6

void setup() 
{
    pinMode(LED_R, OUTPUT);
    pinMode(LED_G, OUTPUT);
    pinMode(LED_B, OUTPUT);
    color(0,0,0);

    /*Serial.begin(9600);
    while (!Serial);
    */

    color(10,0,0);
    Bridge.begin();
    color(0,0,0);
}

void loop() 
{
    char buffer[7] = {0};
    Bridge.get("color", buffer, 6);

    //Serial.print("C: "); Serial.println(buffer);

    unsigned long c = strtoul(buffer, NULL, HEX);
    
    byte r = (c & 0xFF0000) >> 16;
    byte g = (c & 0x00FF00) >> 8;
    byte b = (c & 0x0000FF);

    color(r, g, b);
    delay(20);
}


void color(byte r, byte g, byte b)
{
  analogWrite(LED_R, r);
  analogWrite(LED_G, g);
  analogWrite(LED_B, b);
}

