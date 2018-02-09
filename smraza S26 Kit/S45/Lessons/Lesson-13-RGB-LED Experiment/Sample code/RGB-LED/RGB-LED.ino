/*
 * Author: SMRAZA KEEN
 * Date:2016/07/21
 * IDE V1.6.9
 * Address:http://www.amazon.com/shops/smraza
 * Function:
 */
const int Rled=5;
const int Gled=6;
const int Bled=7;
void setup() 
{
  pinMode(Rled,OUTPUT);
  pinMode(Gled,OUTPUT);
  pinMode(Bled,OUTPUT);
}
void loop() 
{
  digitalWrite(Rled,HIGH);
  digitalWrite(Gled,LOW);
  digitalWrite(Bled,LOW);
  delay(1000);
  digitalWrite(Rled,LOW);
  digitalWrite(Gled,HIGH);
  digitalWrite(Bled,LOW);
  delay(1000);
  digitalWrite(Rled,LOW);
  digitalWrite(Gled,LOW);
  digitalWrite(Bled,HIGH);
  delay(1000);
}
