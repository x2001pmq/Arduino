/*
 * Author: SMRAZA KEEN
 * Date:2016/9/29
 * IDE V1.6.9
 * Email:TechnicSmraza@outlook.com
 * Function:
 * Tips:Open the serial port
 */
int gas_sensor =A0;
int Buzzer=6;   
void setup()
{
  pinMode(Buzzer,OUTPUT); 
  Serial.begin(9600);
}
void loop()
{
  int val;
  val=analogRead(gas_sensor);
  Serial.println(val,DEC);
  while(val<500) 
     {
        digitalWrite(Buzzer,HIGH); 
        val=analogRead(0);   
        Serial.println(val,DEC);
      }
  digitalWrite(Buzzer,LOW); 
}
