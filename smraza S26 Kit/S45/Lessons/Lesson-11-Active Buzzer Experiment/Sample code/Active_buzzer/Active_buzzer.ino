/*
 * Author: SMRAZA KEEN
 * Date:2016/07/21
 * IDE V1.6.9
 * Address:http://www.amazon.com/shops/smraza
 * Function:
 */
const int Data = 8;
void setup() 
{
 pinMode(Data,OUTPUT);
}
void loop()
{
  digitalWrite(Data,HIGH);
  delay(500);
  digitalWrite(Data,LOW);
  delay(500);
}
