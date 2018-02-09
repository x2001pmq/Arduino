/*
 * Author: SMRAZA KEEN
 * Date:2016/6/29
 * IDE V1.6.9
 * Email:TechnicSmraza@outlook.com
 * Function:
 */
int motor = 8;           // motor turn-on trigger signal - active high; 
void setup (void)
{
pinMode (motor, OUTPUT); // define port attribute for the output;
}
void loop (void)
{
digitalWrite (motor, HIGH); // 
delay (1000);
digitalWrite (motor, LOW);  //switch; 
delay (1000);
}

