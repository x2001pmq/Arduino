/*
 * Author: SMRAZA KEEN
 * Date:2016/07/21
 * IDE V1.6.9
 * Address:http://www.amazon.com/shops/smraza
 * Function:
 */
const int Laser=8;
void setup() 
{
  pinMode(Laser,OUTPUT);
}
void loop() 
{
  digitalWrite(Laser,HIGH);
  delay(1000);
  digitalWrite(Laser,LOW);
  delay(1000);
}
