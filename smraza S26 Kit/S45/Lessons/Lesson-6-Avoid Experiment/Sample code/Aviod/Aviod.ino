/*
 * Author: SMRAZA KEEN
 * Date:2016/6/29
 * IDE V1.6.9
 * Email:TechnicSmraza@outlook.com
 * Function:
 * Tips:Open the serial port
 */
const int OUT = 7;
const int EN  = 8;
int Data=0;
void setup()
{
  pinMode(EN,OUTPUT);
  pinMode(OUT,INPUT);
  digitalWrite(EN,HIGH); //High level start, low level off.
  Serial.begin(9600);
}
void loop()
{
  Data=digitalRead(OUT);
  Serial.println(Data);
}

