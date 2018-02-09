/*
 * Author: SMRAZA KEEN
 * Date:2016/07/21
 * IDE V1.6.9
 * Address:http://www.amazon.com/shops/smraza
 * Function:
 */
const int SensorPin = 8;
int Data=0;
void setup()
{
pinMode (SensorPin,INPUT);
Serial.begin(9600);
}
void loop()
{
  Data=digitalRead(SensorPin);
  Serial.print("Data=");
  if(Data==HIGH)
  {
     Serial.println("Close");
  }
  else
  {
     Serial.println("Open");
  }
  delay(300);
}
