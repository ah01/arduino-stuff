
#include <Bridge.h>;
#include <SoftwareSerial.h>;

SoftwareSerial sSerial(8, 9); // RX, TX

#define FSTREAM sSerial
#define LED 13

#include "parser.h";

void setup()
{
    FSTREAM.begin(38400);

    //Serial.begin(9600);

    pinMode(LED, OUTPUT);

    //while (!Serial);
    //Serial.println("init");
    
    digitalWrite(LED, HIGH);
    Bridge.begin();
    digitalWrite(LED, LOW);
}

void loop()
{
    if (fridge_read() == true)
    {
        //fridge_print();

        digitalWrite(LED, HIGH);

        set_value("i", fridge_temps.i);
        set_value("A", fridge_temps.A);
        set_value("B", fridge_temps.B);
        set_value("P", fridge_temps.P);
        set_value("V", fridge_temps.V);
        set_value("Z", fridge_temps.Z);

        set_value("D", fridge_temps.Open);

        set_value("time", millis());

        digitalWrite(LED, LOW);
    }
}

void set_value(const char *key, float value)
{
    String s = String(value);
    Bridge.put(key, s);
}

void set_value(const char *key, unsigned long value)
{
    String s = String(value);
    Bridge.put(key, s);
}

void set_value(const char *key, bool value)
{
    Bridge.put(key, value ? "1" : "0");
}
