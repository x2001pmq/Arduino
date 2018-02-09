/************************************************************************
  Simple OBD Data Display
  Works with any Arduino board connected with SH1106 128*64 I2C OLED and
  Freematics OBD-II UART Adapter - https://freematics.com/products
  Distributed under public domain
  Written by Stanley Huang <stanley@freematics.com.au>
*************************************************************************/

//#include <OBD2UART.h>
#include <OBD.h>
//#include <Arduino.h>
#include <U8g2lib.h>

#ifdef U8X8_HAVE_HW_SPI
#include <SPI.h>
#endif
#ifdef U8X8_HAVE_HW_I2C
#include <Wire.h>
#endif

#define dRPM 0x7A
#define dKMH 0x78

U8G2_SH1106_128X64_NONAME_F_HW_I2C u8g2(U8G2_R0, /* reset=*/ U8X8_PIN_NONE);
//U8G2_SH1106_128X64_NONAME_F_HW_I2C u8g22(U8G2_R0, /* reset=*/ U8X8_PIN_NONE);

COBD obd;

int lightPin = 0;  //define a pin for Photo resistor

void reconnect()
{
  u8g2.setI2CAddress(dKMH);
  u8g2.clear();
  //u8g2.setFont(u8g2_font_ncenB08_tr);
  u8g2.print(999);
  //u8g2.drawStr(0, 20, "C6_KMH");
  //u8g2.drawStr(0, 63, "RECONNECTING"); // write something to the internal memory
  u8g2.sendBuffer();
 
}

#define FLAG_PAD_ZERO 1

void printInt(uint16_t value, int8_t padding)
{
    uint16_t den = 10000;
    for (int8_t i = 5; i > 0; i--) {
        byte v = (byte)(value / den);
        value -= v * den;
        den /= 10;
        if (v == 0 && padding && den) {
            if (padding >= i) {
                //writeDigit((m_flags & FLAG_PAD_ZERO) ? 0 : -1);
               
                  u8g2.print((FLAG_PAD_ZERO) ? 0 : -1);
               
            }
            continue;
        }
        padding = 0;
        //writeDigit(v);
                  u8g2.print(v);
        
    }
  for (uint16_t i = 0; !obd.init(); i++) {
    if (i == 5) {
      u8g2.clear();
    }
    //delay(3000);
  }
}

void showData(byte pid, int value)
{
  switch (pid) {
      case PID_RPM:
        //lcd.setCursor(64, 0);
        //lcd.setFontSize(FONT_SIZE_XLARGE);
        //lcd.printInt((unsigned int)value % 10000, 4);
        u8g2.setI2CAddress(dRPM);
        u8g2.clearBuffer();
        //u8g2.setFont(u8g2_font_logisoso54_tn);
        u8g2.setCursor(14, 60);
        printInt((unsigned int)value % 10000,4);  // write something to the internal memory
        u8g2.sendBuffer();
        break;
    case PID_SPEED:
      //lcd.setCursor(0, 0);
      //lcd.setFontSize(FONT_SIZE_XLARGE);
      //lcd.printInt((unsigned int)value % 1000, 3);

      u8g2.setI2CAddress(dKMH);
      u8g2.clearBuffer();
      //u8g2.setFont(u8g2_font_logisoso54_tn);
      u8g2.setCursor(14, 60);
      printInt((unsigned int)value % 1000, 3);
      u8g2.sendBuffer();

      break;
      
      //  case PID_THROTTLE:
      //    //lcd.setCursor(88, 5);
      //    //l/cd.setFontSize(FONT_SIZE_MEDIUM);
      //    //lcd.printInt(value % 100, 3);
      //    //lcd.setFontSize(FONT_SIZE_SMALL);
      //    //lcd.print(" %");
      //    u8g2.setFont(u8g2_font_ncenB08_tr);
      //    u8g2.drawStr(88,5,value % 100);  // write something to the internal memory
      //    u8g2.sendBuffer();
      //
      //    break;
      //  case PID_ENGINE_LOAD:
      //    //lcd.setCursor(12, 5);
      //    //lcd.setFontSize(FONT_SIZE_MEDIUM);
      //    //lcd.printInt(value, 3);
      //    //lcd.setFontSize(FONT_SIZE_SMALL);
      //    //lcd.print(" %");
      //    u8g2.setFont(u8g2_font_ncenB08_tr);
      //    u8g2.drawStr(12,5,value % 100);  // write something to the internal memory
      //    u8g2.sendBuffer();
      //
      //    break;
  }
}

void initScreen()
{
  u8g2.clear();
}

//void set_contrast(){
//  int photo = analogRead(0);
//  
//  photo = map(photo, 0, 700, 0, 255);
//  //Serial.println(photo);
//  int contrast;
//  if (photo < 150) {
//    contrast = 0;
//  }
//  else {
//    contrast = 255;
//  }
//
//  u8g2.setI2CAddress(dRPM);
//  u8g2.setContrast(contrast);
//  u8g2.setI2CAddress(dKMH);
//  u8g2.setContrast(contrast);
//
//}

void setup()
{
 
  //Serial.begin(9600);  //Begin serial communcation
  
  u8g2.setFont(u8g2_font_logisoso54_tn);
  u8g2.setI2CAddress(dKMH);
  u8g2.begin();
  u8g2.setContrast(255);
  //u8g2.setCursor(0, 20);
  u8g2.setCursor(14, 60);
  //u8g2.setFont(u8g2_font_ncenB08_tr);
  u8g2.print(1);
  //u8g2.drawStr(0, 20, "C6_KMH");
  u8g2.sendBuffer();

  u8g2.setI2CAddress(dRPM);
  //u8g2.setFont(u8g2_font_logisoso54_tn);
  u8g2.setFont(u8g2_font_fub49_tn);
  u8g2.clearBuffer();
  u8g2.begin();
  u8g2.setContrast(255);
  //u8g2.setCursor(0, 20);
  u8g2.setCursor(14, 60);
  //u8g2.setFont(u8g2_font_ncenB08_tr); 
  //u8g2.drawStr(0, 20, "C6_RPM");
  u8g2.print(2);
  u8g2.sendBuffer();

  delay(500);
  obd.begin();

  while (!obd.init());
  initScreen();
}


void loop()
{
    // For the returned value to be within OLED display contrast limit of 0-255
  
  //set_contrast();

//  int r;
//  //Testing
//  u8g2.setI2CAddress(dRPM);
//  r = rand()/220;
//
//  u8g2.clearBuffer();
//  u8g2.setFont(u8g2_font_logisoso54_tn);
//  u8g2.setCursor(14, 60);
//  u8g2.print(r);
//      u8g2.sendBuffer();
//
//  
//  u8g2.setI2CAddress(dKMH);
//  r = rand()/220;
//  u8g2.clearBuffer();
//  u8g2.setFont(u8g2_font_logisoso54_tn);
//  u8g2.setCursor(14, 60);
//  u8g2.print(r);
//      u8g2.sendBuffer();

  
  //for (int i = 110; i > 0; i++) {
  //      byte v = (byte)(value / den);
  //      value -= v * den;

  //Serial.println(analogRead(0)); //Write the value of the photoresistor to the serial monitor.
  
  //static byte pids[]= {PID_RPM, PID_SPEED, PID_ENGINE_LOAD, PID_THROTTLE};
  static byte pids[]= {PID_RPM, PID_SPEED};
  //static byte pids[] = {PID_SPEED};
  static byte index = 0;
  byte pid = pids[index];
  int value;

  // send a query to OBD adapter for specified OBD-II pid
  if (obd.readPID(pid, value)) {
    showData(pid, value);
  }

  // send a query to OBD adapter for specified OBD-II pid
//  if (obd.readPID(PID_RPM, value)) {
//        //u8g22.setI2CAddress(dRPM);
//        u8g22.clearBuffer();
//        //u8g2.setFont(u8g2_font_logisoso54_tn);
//        //u8g22.setCursor(14, 60);
//        //printInt((unsigned int)value % 10000,3);  // write something to the internal memory
//        u8g22.print((unsigned int)value % 10000);  // write something to the internal memory
//        u8g22.sendBuffer();
//  }
//
//  if (obd.readPID(PID_SPEED, value)) {
//      //u8g2.setI2CAddress(dKMH);
//      u8g2.clearBuffer();
//      //u8g2.setFont(u8g2_font_logisoso54_tn);
//      //u8g2.setCursor(14, 60);
//      //printInt((unsigned int)value % 1000, 3);
//      u8g2.print((unsigned int)value % 1000);
//      u8g2.sendBuffer();
//  }
  
  index = (index + 1) % sizeof(pids);

  if (obd.errors >= 2) {
    reconnect();
    setup();
  }
}
