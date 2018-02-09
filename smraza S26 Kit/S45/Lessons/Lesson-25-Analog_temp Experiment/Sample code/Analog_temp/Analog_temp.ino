/*
 * Author: SMRAZA KEEN
 * Date:2016/6/29
 * IDE V1.6.9
 * Email:TechnicSmraza@outlook.com
 * Function:
 * Tips:Open the serial port
 */
const int SensorPin = A0;
int Data=0;
void setup()
{
  pinMode (SensorPin,INPUT);
  Serial.begin(9600);
}
void loop()
{
  Data=analogRead(SensorPin);
  Serial.print("Data=");
  Serial.print(Data);
  Serial.println("\n");
  delay(500);
}
