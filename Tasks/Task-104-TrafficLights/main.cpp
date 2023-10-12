#include "uop_msb.h"
#include <iterator>
#include <type_traits>
using namespace uop_msb;

#define WAIT_TIME_MS 500 

DigitalOut red(TRAF_RED1_PIN,1);         //Note the initial state
DigitalOut amber(TRAF_YEL1_PIN,0);
DigitalOut green(TRAF_GRN1_PIN,0);

LCD_16X2_DISPLAY lcd;


int main()
{
 while(true) {

    amber = 0;
    red = 1;
    lcd.cls();
    lcd.puts("RED");
    wait_us(10000000);

    amber = 1;
    lcd.cls();
    lcd.puts("Amber");
    wait_us(2000000);

    green = 1;
    amber = 0;
    red = 0;
    lcd.cls();
    lcd.puts("Green");    
    wait_us(10000000);

    amber = 1;
    green = 0;
    lcd.cls();
    lcd.puts("Amber");
    wait_us(2000000);


 }

   // lcd.cls();
   // lcd.puts("TASK-104");

   // while (true)
    //{
      //  red = !red;
      //  amber = !amber;
       // green = !green;
     //   wait_us(WAIT_TIME_MS * 1000);
   // }
}
