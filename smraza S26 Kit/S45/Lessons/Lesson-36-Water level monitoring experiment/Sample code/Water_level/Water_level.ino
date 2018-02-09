/*
 * Author: SMRAZA KEEN
 * Date:2016/6/29
 * IDE V1.6.9
 * Email:TechnicSmraza@outlook.com
 * Function:
 */
int water = A0;
double val;
double count;
void setup()                                                                                     
{
  Serial.begin(9600);
  Serial.print("Welcome to ");
  Serial.println("Smraza");
}
void loop()
{ 
  val=analogRead(water);
  Serial.println(val);
  count=(val/650)*4;
  Serial.print("Water Level=%");            
  Serial.println(count);
  delay(500);   
}
