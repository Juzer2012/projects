
const int LDR = A0; // set pin Analog 0 for LDR
const int MainsRelay = 3; // set pin 3 for 240v Relay
const int threshold = 300; // set threshold value of LDR(calibrate to your needs)
const int wire1 = 4; // set pin 4 for Keypad controller Pin 1
const int wire2 = 5; // set pin 5 for Keypad controller Pin 2
const int wire3 = 6; // set pin 6 for Keypad controller Pin 3
const int btnPin = A2;// set Analog 2 for MCB sensor
int btnVal = 0;// variable to store the MCB sensor's value
void SMS_error();// function to send the error message
int LDRval = 0; // variable to store the LDR value
boolean flag1 = 0;
boolean flag2 = 0;

void setup() {

  pinMode(LDR, INPUT); // set LDR as Input
  pinMode(MainsRelay, OUTPUT); // set 240v relay as Output
  pinMode(btnPin, INPUT); // set MCB sensor as Input
  pinMode(wire1, OUTPUT); // set Keypad controller Pin 1 as OUTPUT
  pinMode(wire2, OUTPUT); // set Keypad controller Pin 2 as OUTPUT
  pinMode(wire3, OUTPUT); // set Keypad controller Pin 3 as OUTPUT
  digitalWrite(MainsRelay,LOW); // set the state of the 240v relay as LOW, during system bootup
}

void loop() {

  LDRval = analogRead(LDR); 
  btnVal = analogRead(btnPin);
  flag1 = (LDRval > threshold) && digitalRead(MainsRelay == LOW);// if the LDR value is more than the threshold and the 240v relay is OFF.
  flag2 = (LDRval > threshold) && digitalRead(MainsRelay == HIGH);// if the LDR value is more than the threshold and the 240v relay is ON.

  if (flag1)//SMS Recieved and Relay is OFF
  {
    digitalWrite(MainsRelay,HIGH);// Turn the relay on

  }

  else if (flag2)//SMS Recieved and Relay is ON

  {
    digitalWrite(MainsRelay,LOW);// Turn the relay off
  }
  if (btnVal > threshold)// if the state-detection sensor is tripped
  {
    SMS_error();//send the error SMS
  }

}

void SMS_error(){

  digitalWrite(wire2,HIGH);//relay on
  delay(1000);// calibrate the delay to your phone. Remember that the delay is in milliseconds(1000 milliseconds = 1 second)
  digitalWrite(wire2,LOW);//relay off
  delay(1000);
  digitalWrite(wire2,HIGH);
  delay(1000);
  digitalWrite(wire2,LOW);
  delay(1000);
  digitalWrite(wire2,HIGH);
  delay(1000);
  digitalWrite(wire2,LOW);
  delay(1000);
  digitalWrite(wire2,HIGH);
  delay(1000);
  digitalWrite(wire2,LOW);
  delay(1000);
  digitalWrite(wire2,HIGH);
  delay(1000);
  digitalWrite(wire2,LOW);
  delay(1000);
  digitalWrite(wire3,HIGH);
  delay(1000);
  digitalWrite(wire3,LOW);
  delay(1000);
  digitalWrite(wire2,HIGH);
  delay(1000);
  digitalWrite(wire2,LOW);
  delay(1000);
} 










