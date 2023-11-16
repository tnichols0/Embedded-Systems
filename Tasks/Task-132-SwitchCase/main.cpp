#include "uop_msb.h"
using namespace uop_msb;

BusIn buttons(PG_0, PG_1, PG_2, PG_3);

DigitalOut redLED(TRAF_RED1_PIN);       //Red Traffic 1
DigitalOut yellowLED(TRAF_YEL1_PIN);    //Yellow Traffic 1
DigitalOut greenLED(TRAF_GRN1_PIN);     //Green Traffic 1

//Dual Digit 7-segment Display
LatchedLED disp(LatchedLED::SEVEN_SEG);

int main()
{
    int count = 0;
    
    //Configure switches
    buttons[2].mode(PullDown);
    buttons[3].mode(PullDown);

    //Turn ON the 7-segment display
    disp.enable(true);

    //Update display
    disp = count;

    while (true) {
        
        //Read button without blocking
        int btn = buttons;     //Local to the while-loop  

        switch (btn) {

            case 1:
            //Button A only
            redLED = !redLED;
            yellowLED = 0;            
            greenLED = 0;
            break;

            case 2: 
            //Button B
            redLED = 0;
            yellowLED = !yellowLED;            
            greenLED = 0;
            break;

            case 4:
            //Button C
            redLED = 0;
            yellowLED = 0;
            greenLED = !greenLED;
            break;

            case 8:
            //Button D
            redLED = !redLED;
            yellowLED = !yellowLED;
            greenLED = !greenLED;
            break;

            default:
            //All others
            greenLED = 1;
            yellowLED = 1;
            redLED = 1;
            break;

        }

        // Slow it down a bit (and debounce the switches)
        wait_us(100000);  
    }
}



