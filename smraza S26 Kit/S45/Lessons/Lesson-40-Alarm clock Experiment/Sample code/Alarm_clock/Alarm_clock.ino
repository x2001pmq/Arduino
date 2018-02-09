/*
 * Author: SMRAZA KEEN
 * Date:2016/6/29
 * IDE V1.6.9
 * Email:TechnicSmraza@outlook.com
 * Function:
 */
#include <DS3231.h>
#include <Wire.h> 
const int Data = 8;
//initialize variable
DS3231 Clock;
boolean Century=false;
boolean h12;
boolean PM;
byte ADay, AHour, AMinute, ASecond, ABits;
boolean ADy, A12h, Apm;
int second,minute,hour,date,month,year,val; 

void setup(void) 
{
  Wire.begin();
  Serial.begin(9600);
  pinMode(Data,OUTPUT);
}
 
void ReadDS3231()
{
  int second,minute,hour,date,month,year,pm; 
  second=Clock.getSecond();
  minute=Clock.getMinute();
  hour=Clock.getHour(h12,PM);
  date=Clock.getDate();
  month=Clock.getMonth(Century);
  year=Clock.getYear();
  Serial.print("20");
  Serial.print(year,DEC);
  Serial.print('-');
  Serial.print(month,DEC);
  Serial.print('-');
  Serial.print(date,DEC);
  Serial.print(' ');
  Serial.print(hour,DEC);
  Serial.print(':');
  Serial.print(minute,DEC);
  Serial.print(':');
  Serial.print(second,DEC);
  Serial.print('\n');
}
void loop() 
{
  ReadDS3231();
  if((hour==8)&&(minute==0)&&(second==0))
  {
    digitalWrite(Data,LOW);
    delay(500);
    }
    else{
      digitalWrite(Data,HIGH);
      delay(500);
      }
  delay(150);
}

