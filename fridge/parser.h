/*

Ti:+023.45 A:+023.45 B:+023.45 P:+023.45 V:+023.45 Z:+023.45 <cr><lf>
Ti:+010.45 A:+012.45 B:+013.45 P:+014.45 V:+015.45 Z:+016.45 <cr><lf>


Ti:+010.45 A:+012.45 B:+013.45 P:+014.45 V:+015.45 Z:+016.45 O
Ti:+010.45 A:+012.45 B:+013.45 P:+014.45 V:+015.45 Z:+016.45 C

*/

#include <Arduino.h>



typedef struct ftemps_S {
    float i;
    float A;
    float B;
    float P;
    float V;
    float Z;
    bool Open;
} Ftemps;

ftemps_S fridge_temps;



bool fridge_read()
{
    if (FSTREAM.findUntil("Ti:", "\r") == false) 
    {
        return false;
    }

Serial.println("find Ti:");

    fridge_temps.i = FSTREAM.parseFloat();
    fridge_temps.A = FSTREAM.parseFloat();
    fridge_temps.B = FSTREAM.parseFloat();
    fridge_temps.P = FSTREAM.parseFloat();
    fridge_temps.V = FSTREAM.parseFloat();
    fridge_temps.Z = FSTREAM.parseFloat();

    FSTREAM.findUntil(" ", "\r");

    int c = FSTREAM.read();

    if (c == 'O')
    {
        fridge_temps.Open = true;
    }
    else if (c == 'C')
    {
        fridge_temps.Open = false;
    }

    return true;
}



void fridge_print()
{
    Serial.print("i:"); Serial.println(fridge_temps.i);
    Serial.print("A:"); Serial.println(fridge_temps.A);
    Serial.print("B:"); Serial.println(fridge_temps.B);
    Serial.print("P:"); Serial.println(fridge_temps.P);
    Serial.print("V:"); Serial.println(fridge_temps.V);
    Serial.print("Z:"); Serial.println(fridge_temps.Z);
    
    Serial.print("D:"); Serial.println(fridge_temps.Open ? "1" : "0");

    Serial.println();
}


