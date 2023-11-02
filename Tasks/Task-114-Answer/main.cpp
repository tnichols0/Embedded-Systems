#include "mbed.h"

DigitalOut redLED(PC_2);
DigitalOut greenLED(PC_6);
DigitalOut yellowLED(PC_3);


int main()
{
    redLED = 1;
    yellowLED = 1;
    greenLED = 1;
    while (true) {

        //Red Light
        redLED = 1;
        yellowLED = 0;
        greenLED = 0;
        wait_us(2000000);
        //Red + Yellow Light
        redLED = 1;
        yellowLED = 1;
        greenLED = 0;
        wait_us(2000000);
        //Green Light
        redLED = 0;
        yellowLED = 0;
        greenLED = 1;
        wait_us(2000000);
        //Flashing Yellow Light (4 times)
        int count = 0;
        while (count < 4) {
            redLED = 0;
            yellowLED = 1;
            greenLED = 0;
            wait_us(250000);
            yellowLED = 0;
            wait_us(250000);
            count = count + 1;
        }
        
    }
}

