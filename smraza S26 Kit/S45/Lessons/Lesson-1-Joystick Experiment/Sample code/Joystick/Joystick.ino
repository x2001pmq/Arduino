/*
 * Author: SMRAZA KEEN
 * Date:2016/6/29
 * IDE V1.6.9
 * Email:TechnicSmraza@outlook.com
 * Function:
 * Tips:Open the serial port
 */
int xpotPin = A0;  //Set port
int ypotPin = A1;            
int bpotPin = 13; 
int xval=0;    //Initialize a variable
int yval=0;
int bval=0;
void setup()                                                                                     
{
  pinMode(xpotPin,INPUT);
  pinMode(ypotPin,INPUT);
  pinMode(bpotPin,INPUT); 
  Serial.begin(9600);
}
void loop()
{ 
  xval = analogRead(xpotPin);   //Read Values from the xpotPin
  yval = analogRead(ypotPin);   
  bval = digitalRead(bpotPin);   
  Serial.print("xval=");
  Serial.print(xval);
  Serial.print('\t');
  Serial.print("yval=");
  Serial.print(yval);
  Serial.print('\t');
  Serial.print("bval=");
  Serial.println(bval);
  delay(200);
}
