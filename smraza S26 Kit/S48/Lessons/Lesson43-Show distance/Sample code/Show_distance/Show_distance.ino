/*
 * Author: SMRAZA KEEN
 * Date:2016/6/29
 * IDE V1.6.9
 * Email:TechnicSmraza@outlook.com
 * Function:
 */
// initialize the library with the numbers of the interface pins
#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
const int TrigPin = 52;
const int EchoPin = 53;
float cm;
void setup()                                                                                     
{
// set up the LCD's number of columns and rows:
  lcd.begin(16,2);
// Print a message to the LCD.
  lcd.print("  Welcome to ");
  lcd.setCursor(0,1);  //Display position
  lcd.print("        Smraza");
  Serial.begin(9600);
  pinMode(TrigPin, OUTPUT);
  pinMode(EchoPin, INPUT);
}
void loop()
{
  digitalWrite(TrigPin, LOW);       
  delayMicroseconds(2);
  digitalWrite(TrigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(TrigPin, LOW);
  cm = pulseIn(EchoPin, HIGH) / 58.0; //The echo time is converted into cm
  cm = (int(cm * 100.0)) / 100.0;     //Keep two decimal places
  Serial.print("Distance\t=\t");
  Serial.print(cm);
  Serial.print("cm");
  Serial.println();
  lcd.clear();                   //clear display
  lcd.setCursor(0,0) ;
  lcd.print("Smraza");           //display "Smraza"
  lcd.setCursor(0,1) ;           //Display position
  lcd.print("Distance=");            //display"Distance="
  lcd.print(cm);
  lcd.print("cm");
  delay(1000);
 }

