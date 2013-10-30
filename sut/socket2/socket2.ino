#include <Bridge.h>
#include <Mailbox.h>

#define RF_OUTPUT_PIN 2
#define LED_PIN 13

#include "rf.h"

const char* on_code  = "111110FFFFF0S";
const char* off_code = "111110FFFF0FS";
const int period = 150;

void setup()
{
    Serial.begin(9600);

    pinMode(RF_OUTPUT_PIN, OUTPUT);
    pinMode(LED_PIN, OUTPUT);

    digitalWrite(LED_PIN, HIGH);
    Bridge.begin();
    digitalWrite(LED_PIN, LOW);

    Mailbox.begin();
}

void loop()
{
    String command;

    if (Mailbox.messageAvailable() > 0)   
    {
        Mailbox.readMessage(command, 32);
        Serial.println(command);
    
        if (command == "on") 
        {
            rf_send(on_code, period, 5);
            Serial.println("ON");
        }
        else if (command == "off")
        {
            rf_send(off_code, period, 5);
            Serial.println("OFF");
        }
        else
        {
            Serial.println("unknown command");
        }
    }

    delay(50);
}
