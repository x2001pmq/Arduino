/*
 * Author: SMRAZA KEEN
 * Date:2016/07/21
 * IDE V1.6.9
 * Address:http://www.amazon.com/shops/smraza
 * Function:
 */
#define TOUCH_SIG 8   
boolean get_touch(){  
  boolean touch_stat=0;  
  touch_stat=digitalRead(TOUCH_SIG); 
  return touch_stat;  
}  
  
void setup() {  
  // put your setup code here, to run once:  
  pinMode(TOUCH_SIG,INPUT);         
  Serial.begin(9600);  
}  
  
void loop() {  
  boolean touch_stat;  
  // put your main code here, to run repeatedly:  
  Serial.print("\nrunning\nTouch Stat - ");  
  touch_stat=get_touch();  
  Serial.print(touch_stat);  
  delay(1000);  
}  
