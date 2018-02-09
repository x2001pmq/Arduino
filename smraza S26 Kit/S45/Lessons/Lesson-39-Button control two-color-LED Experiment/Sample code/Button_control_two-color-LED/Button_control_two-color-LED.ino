/*
 * Author: SMRAZA KEEN
 * Date:2016/07/21
 * IDE V1.6.9
 * Address:http://www.amazon.com/shops/smraza
 * Function:
 */
const int Rled=6;
const int Yled=7;
const int SensorPin = 8;
int Data=0;
void setup()
{
  pinMode(Rled,OUTPUT);
  pinMode(Yled,OUTPUT);
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
     digitalWrite(Rled,HIGH);
     digitalWrite(Yled,LOW);
     delay(1000);
  }
  else
  {
     Serial.println("Open");
     digitalWrite(Rled,LOW);
     digitalWrite(Yled,HIGH);
     delay(1000);
  }
  delay(300);
}
