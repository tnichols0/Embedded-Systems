#include "uop_msb.h"
using namespace uop_msb;

Buzzer buzz;

DigitalOut led1(LED1);
DigitalOut led2(LED2);
DigitalOut led3(LED3);


int main()
{
    printf("\nTASK-112\n");

    //getchar
    char c1, c2;
    printf("\n\nPress a key\n");
    c1 = getchar();
    printf("You entered character %c which has the ASCII code %d\n", c1, c1);

    printf("\n\nPress another key\n");
    c2 = getchar();
    printf("You entered character %c which has the ASCII code %d\n", c2, c2);

    //Lights on
    printf("\n\nTo set the delay the lights stay on for (in ms), type in an integer number and press return\n");
    int delay_ms_on;
    int parsedon = scanf("%d", &delay_ms_on);
    
    printf("You entered %d correct integer values. The value was %dms\n", parsedon, delay_ms_on);

    //Lights off
    printf("\n\nTo set the delay the lights stay off for (in ms), type in an integer number and press return\n");
    int delay_ms_off;
    int parsedoff = scanf("%d", &delay_ms_off);
    
    printf("You entered %d correct integer values. The value was %dms\n", parsedoff, delay_ms_off);

    // Stop
    while (parsedon > 0) {
        wait_us(delay_ms_on * 1000);
        led1 = 1;
        led2 = 1;
        led3 = 1;
        wait_us(delay_ms_off * 1000);
        led1 = 0;
        led2 = 0;
        led3 = 0;        
    } 

    printf("Invalid - please restart and try again\n");
    while(1);    
}