#include <Arduino.h>
#include <Bounce2.h>

#include "Keyboard.h"

// http://arduino.cc/en/Reference/MouseKeyboard
// http://arduino.cc/en/Reference/KeyboardModifiers

#define PEDAL_PIN 2

Bounce pedal = Bounce();

void setup()
{
    //Serial.begin(9600);

    pinMode(PEDAL_PIN, INPUT_PULLUP);

    pedal.attach(PEDAL_PIN);
    pedal.interval(5);

    Keyboard.begin();
}

void loop()
{
    pedal.update();

    if (pedal.fallingEdge())
    {
        //Serial.println("falling");

        //Keyboard.press(KEY_ESC);
        //delay(100);
        //Keyboard.releaseAll();

        Keyboard.print("gt");
    }

    if (pedal.risingEdge())
    {
        //Serial.println("rising");
    }
}
