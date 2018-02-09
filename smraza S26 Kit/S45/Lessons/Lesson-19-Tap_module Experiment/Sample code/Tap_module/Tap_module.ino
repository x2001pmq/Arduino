/*
 * Author: SMRAZA KEEN
 * Date:2016/6/29
 * IDE V1.6.9
 * Email:TechnicSmraza@outlook.com
 * Function:
 * Tips:Open the serial port
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
     Serial.println("Open");
  }
  else
  {
     Serial.println("Close");
  }
  delay(300);
}
