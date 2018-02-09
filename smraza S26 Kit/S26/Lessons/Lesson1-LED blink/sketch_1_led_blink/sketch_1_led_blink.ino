
//Pin 13 has an led connected on the board
int led = 13;

void setup() {
  // put your setup code here, to run once:

  //Initialize the digital pin as an output
  pinMode(led,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(led,HIGH);
  delay(100);
  digitalWrite(led, LOW);
  delay(100);
}
