/*
 * Author: SMRAZA KEEN
 * Date:2016/6/29
 * IDE V1.6.9
 * Email:TechnicSmraza@outlook.com
 * Function:
 * Tips:Open the serial port
 */
const int SensorPin = A0;
const int buzzer = 8;
int Data=0;
void setup()
{
pinMode(buzzer,OUTPUT);
pinMode (SensorPin,INPUT);
Serial.begin(9600);
}
void loop()
{
  Data=analogRead(SensorPin);
  Serial.print("Data=");
  Serial.print(Data);
  Serial.println("\n");
  if(Data<500){
      digitalWrite(buzzer,HIGH);
      delay(500);
    }
    else
    {
      digitalWrite(buzzer,LOW);
      delay(500);
      }
  delay(500);
}
