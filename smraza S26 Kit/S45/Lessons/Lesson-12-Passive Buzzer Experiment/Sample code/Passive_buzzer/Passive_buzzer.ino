/*
 * Author: SMRAZA KEEN
 * Date:2016/07/21
 * IDE V1.6.9
 * Address:http://www.amazon.com/shops/smraza
 * Function:
 */
const int buzzer=8;
void setup()
{
  pinMode(buzzer,OUTPUT);
}
void loop()
{
      for(int i=200;i<=800;i++)              
    {
      tone(buzzer,i);                           
      delay(5);                           
    }
    delay(4000);                       
    for(int i=800;i>=200;i--)
    {
      tone(buzzer,i);
      delay(10);
    }
}
