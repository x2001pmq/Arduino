 /*
 * Author: SMRAZA KEEN
 * Date:2016/6/29
 * IDE V1.6.9
 * Email:TechnicSmraza@outlook.com
 * Function:
 * Tips:Open the serial port
 *      Add DS18B20 to your libary
 */
#include "DS18B20.h"
DS18B20  ds(8,1);   
void setup() 
{
  
  Serial.begin(9600);
}

void loop() 
{
  ds.start();
  delay(200);
  Serial.println(ds.get(0));
  delay(200);
}
