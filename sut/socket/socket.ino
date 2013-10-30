#include <Bridge.h>
#include <YunServer.h>
#include <YunClient.h> 

#define RF_OUTPUT_PIN 2
#define LED_PIN 13

#include "rf.h"

const char* on_code  = "111110FFFFF0S";
const char* off_code = "111110FFFF0FS";
const int period = 150;

YunServer server;

void setup()
{
    Serial.begin(9600);

    pinMode(RF_OUTPUT_PIN, OUTPUT);
    pinMode(LED_PIN, OUTPUT);

    digitalWrite(LED_PIN, HIGH);
    Bridge.begin();
    digitalWrite(LED_PIN, LOW);

    // Listen for incoming connection only from localhost
    // (no one from the external network could connect)
    server.listenOnLocalhost();
    server.begin();
}

void loop()
{
    YunClient client = server.accept();

    if (client) {
    
        String command = client.readString();
        command.trim();
        Serial.println(command);

        if (command == "on") 
        {
            rf_send(on_code, period, 5);
            client.print("done");
        }
        else if (command == "off")
        {
            rf_send(off_code, period, 5);
            client.print("done");   
        }
        else
        {
            client.print("err");
        }

        client.stop();
    }

    delay(50);
}
