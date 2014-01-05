#include <Bounce.h>

// http://arduino.cc/en/Reference/MouseKeyboard
// http://arduino.cc/en/Reference/KeyboardModifiers

#define PEDAL_PIN 2

Bounce pedal = Bounce(PEDAL_PIN, 50); 

void setup()
{
    pinMode(PEDAL_PIN, INPUT_PULLUP);
    Keyboard.begin();
}

void loop()
{
    pedal.update();

    if (pedal.fallingEdge())
    {
        Keyboard.press(KEY_ESC);
        delay(100);
        Keyboard.releaseAll();
    }

    if (pedal.risingEdge())
    {
    }
}
