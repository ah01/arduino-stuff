#include <Bounce.h>

#define PEDAL_PIN 2

Bounce pedal = Bounce(PEDAL_PIN, 100); 

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
        Keyboard.press(KEY_LEFT_CTRL);
        Keyboard.press(KEY_LEFT_SHIFT);
        Keyboard.press('p');
        delay(100);
        Keyboard.releaseAll();
    }

    if (pedal.risingEdge())
    {
        Keyboard.press('\n');
        delay(100);
        Keyboard.releaseAll();
    }
}
