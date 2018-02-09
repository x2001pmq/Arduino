#include <Wire.h>         
#define Register_ID 0   //Configuration Register Address
#define Register_2D 0x2D
#define Register_X0 0x32
#define Register_X1 0x33
#define Register_Y0 0x34
#define Register_Y1 0x35
#define Register_Z0 0x36
#define Register_Z1 0x37
 
int ADXAddress = 0xA7>>1;  //Converted into 7-bit address
int reading = 0;
int val = 0;
int X0,X1,X_out;
int Y0,Y1,Y_out;
int Z1,Z0,Z_out;

const int LedG=2;
const int LedB=6;
const int LedY=9;
const int LedR=12;
void setup()
{
  Wire.begin();  //Initialization IIC
  delay(100);
  Wire.beginTransmission(ADXAddress);
  Wire.write(Register_2D);
  Wire.write(8);
  Wire.endTransmission();
  Serial.begin(9600);
  delay(300);
  pinMode(LedG,OUTPUT);
  pinMode(LedB,OUTPUT);
  pinMode(LedY,OUTPUT);
  pinMode(LedR,OUTPUT);
}
void direction_LED()
{
  if(X_out>100){
    digitalWrite(LedG,HIGH); 
  }
  else{
    digitalWrite(LedG,LOW);
  }
  if(X_out<-100){
    digitalWrite(LedB,HIGH); 
  }
  else{
    digitalWrite(LedB,LOW);
  }
  if(Y_out>100){
    digitalWrite(LedR,HIGH); 
  }
  else{
    digitalWrite(LedR,LOW);
  }
  if(Y_out<-100){
    digitalWrite(LedY,HIGH); 
  }
  else{
    digitalWrite(LedY,LOW);
  }
}
void data_handle(){
  Wire.beginTransmission(ADXAddress);
  Wire.write(Register_X0);
  Wire.write(Register_X1);
  Wire.endTransmission();
  Wire.requestFrom(ADXAddress,2);
  if(Wire.available()<=2);
  {
    X0 = Wire.read();
    X1 = Wire.read();
    X1 = X1<<8;
    X_out = X0+X1;
  }
  Wire.beginTransmission(ADXAddress);
  Wire.write(Register_Y0);
  Wire.write(Register_Y1);
  Wire.endTransmission();
  Wire.requestFrom(ADXAddress,2);
  if(Wire.available()<=2);
  {
    Y0 = Wire.read();
    Y1 = Wire.read();
    Y1 = Y1<<8;
    Y_out = Y0+Y1;
  }
 
  Wire.beginTransmission(ADXAddress);
  Wire.write(Register_Z0);
  Wire.write(Register_Z1);
  Wire.endTransmission();
  Wire.requestFrom(ADXAddress,2);
  if(Wire.available()<=2);
  {
    Z0 = Wire.read();
    Z1 = Wire.read();
    Z1 = Z1<<8;
    Z_out = Z0+Z1;
  }
  /*
  Serial.print("X="); 
  Serial.print(X_out);
  Serial.print("\t");
  Serial.print("Y=");
  Serial.print(Y_out);
  Serial.print("\t");
  Serial.print("Z=");
  Serial.println(Z_out);
  */
}
void loop()
{
  data_handle();
  delay(300);  //Delay 0.3 seconds, the refresh rate is adjusted here
  direction_LED();
}
