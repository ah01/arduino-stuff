#include <Bridge.h>

#define LED_PIN 13
#define THERMOMETER_AD A0

void setup()
{
    Serial.begin(9600);
    pinMode(LED_PIN, OUTPUT);

    digitalWrite(LED_PIN, HIGH);

    // Initialize Bridge 
    Bridge.begin();
    
    digitalWrite(LED_PIN, LOW);

    Bridge.put("name", "Thermometer");
}

void loop()
{
    float t = getTemperature();
    
    Serial.println(t);

    Bridge.put("temp", String(t));
    Bridge.put("time", String(millis()));

    delay(1000);
}

float getTemperature()
{
    float u = (5.0/1024.0) * analogRead(THERMOMETER_AD);

    Serial.print("  ");
    Serial.println(u);

    return (u - 0.5) * 100;
}
