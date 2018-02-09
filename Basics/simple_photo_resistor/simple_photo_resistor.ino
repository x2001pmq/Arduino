/* Simple test of the functionality of the photo resistor

Connect the photoresistor one leg to pin 0, and pin to +5V
Connect a resistor (around 10k is a good value, higher
values gives higher readings) from pin 0 to GND. (see appendix of arduino notebook page 37 for schematics).

----------------------------------------------------

           PhotoR     10K
 +5    o---/\/\/--.--/\/\/---o GND
                  |
 Pin 0 o-----------

----------------------------------------------------
*/

#include <U8g2lib.h>


int lightPin = 0;  //define a pin for Photo resistor
int ledPin=11;     //define a pin for LED

#ifdef U8X8_HAVE_HW_I2C
#include <Wire.h>
#endif

U8G2_SH1106_128X64_NONAME_F_HW_I2C u8g2(U8G2_R0, /* reset=*/ U8X8_PIN_NONE);


void setup()
{
    Serial.begin(9600);  //Begin serial communcation
    //pinMode( ledPin, OUTPUT );
   
  u8g2.begin();
  u8g2.setContrast(0);

}

void loop()
{

  // For the returned value to be within OLED display contrast limit of 0-255
  int photo = analogRead(lightPin);
  photo = map(photo, 0, 700, 0, 255);
  //Serial.println(photo);
  if (photo < 150) {
    u8g2.setContrast(0);
  }
  else {
  u8g2.setContrast(photo);
  }

      u8g2.clearBuffer();
      u8g2.setFont(u8g2_font_logisoso54_tn);
      u8g2.setCursor(14, 60);
      u8g2.print(photo);
      //printInt((unsigned int)value % 1000, 3);
      u8g2.sendBuffer();


    Serial.println(analogRead(lightPin)); //Write the value of the photoresistor to the serial monitor.
    //analogWrite(ledPin, analogRead(lightPin)/4);  //send the value to the ledPin. Depending on value of resistor 
                                                //you have  to divide the value. for example, 
                                                //with a 10k resistor divide the value by 2, for 100k resistor divide by 4.
   //delay(10); //short delay for faster response to light.
}
