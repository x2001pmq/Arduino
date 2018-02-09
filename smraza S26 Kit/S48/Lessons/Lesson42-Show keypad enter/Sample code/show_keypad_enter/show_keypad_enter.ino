/*
 * Author: SMRAZA KEEN
 * Date:2016/6/29
 * IDE V1.6.9
 * Email:TechnicSmraza@outlook.com
 * Function:
 */
// initialize the library with the numbers of the interface pins
#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
#include <Keypad.h>
const byte ROWS = 4; //four rows
const byte COLS = 4; //four columns
//define the cymbols on the buttons of the keypads
char hexaKeys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};
byte rowPins[ROWS] = {38, 40, 42, 44}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {46, 48, 50, 52}; //connect to the column pinouts of the keypad

//initialize an instance of class NewKeypad
Keypad customKeypad = Keypad( makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS); 

void setup()                                                                                     
{
// set up the LCD's number of columns and rows:
  lcd.begin(16,2);
// Print a message to the LCD.
  lcd.print("  Welcome to ");
  lcd.setCursor(0,1);  //Display position
  lcd.print("        Smraza");
  Serial.begin(9600);
}
void loop()
{
  char customKey = customKeypad.getKey();
  if (customKey){
    Serial.println(customKey);
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Enter:"); 
    lcd.print(customKey);
  }
 }

