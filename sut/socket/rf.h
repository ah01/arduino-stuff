
#ifndef _RF_H_
#define _RF_H_

#define RF_SHORT_PULS 1
#define RF_LONG_PULS 3
#define RF_STOP_PULS 32

void rf_send_frame(const char*, unsigned int);
void rf_send_symbol(char, unsigned int);
inline void rf_puls(unsigned int, unsigned int, unsigned int);


void rf_send(const char* data, unsigned int period, unsigned int repeate)
{
    while(repeate-- > 0)
    {
        rf_send_frame(data, period);
    }
}

void rf_send_frame(const char* data, unsigned int period)
{
    int i = 0;
    while(data[i] != 0)
    {
        rf_send_symbol(data[i++], period);
    }
}


void rf_send_symbol(char symbol, unsigned int period)
{
    switch(symbol)
    {
        case '0':
            rf_puls(RF_SHORT_PULS, RF_LONG_PULS, period);
            rf_puls(RF_SHORT_PULS, RF_LONG_PULS, period);
            break;
        case '1':
            rf_puls(RF_LONG_PULS, RF_SHORT_PULS, period);
            rf_puls(RF_LONG_PULS, RF_SHORT_PULS, period);
            break;
        case 'F':
            rf_puls(RF_SHORT_PULS, RF_LONG_PULS, period);
            rf_puls(RF_LONG_PULS, RF_SHORT_PULS, period);
            break;
        case 'S':
            rf_puls(RF_SHORT_PULS, RF_STOP_PULS, period);
            break;
        default:
            return;
    }
}

inline void rf_puls(unsigned int highT, unsigned int lowT, unsigned int baseT)
{
    digitalWrite(RF_OUTPUT_PIN, HIGH);
    delayMicroseconds(baseT * highT);
    digitalWrite(RF_OUTPUT_PIN, LOW);
    delayMicroseconds(baseT * lowT);
}

#endif
