 /*
 * Author: SMRAZA KEEN
 * Date:2016/6/29
 * IDE V1.6.9
 * Email:TechnicSmraza@outlook.com
 * Function:
 * Tips:Open the serial port
 *      Add IRremote to your libary
 */
#include <IRremote.h>   
IRsend irsend;             
void setup()
{
  Serial.begin(9600);    
}
void loop()
{
  Serial.println("SendIR:0x913B4B60 ");
  irsend.sendNEC(0x913B4B60, 32);   
  delay(1000);      
}

