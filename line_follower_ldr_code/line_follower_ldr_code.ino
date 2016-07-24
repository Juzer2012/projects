float LDR1 , LDR2 , LDR3 , LDR4;
int leftOffset = 0, rightOffset = 0, centre1 = 0, centre2 = 0;
int in_1 = 8; int in_2 = 9; int in_3 = 12; int in_4 = 13; int en_1 = 3; int en_2 = 5;
int startSpeed = 255, rotate = 30;
int threshhold = 5;
int left = startSpeed, right = startSpeed;

void calibrate() {
LDR1 = analogRead(0); // read the 4 sensors
LDR2 = analogRead(3);
LDR3 = analogRead(1);
LDR4 = analogRead(2);
leftOffset = leftOffset + LDR4; // add value of left sensor to total
centre1 = centre1 + LDR2; // add value of centre sensor to total
centre2 = centre2 + LDR3;
rightOffset = rightOffset + LDR1; // add value of right sensor to total
// obtain average for each sensor
leftOffset = leftOffset / 10;
rightOffset = rightOffset / 10;
centre1 = centre1 /10;
centre2 = centre2 /10;
// calculate offsets for left and right sensors
leftOffset = centre1 - leftOffset;
rightOffset = centre1 - rightOffset;
}

void setup()
{
 Serial.begin(9600);

// set the motor pins to outputs
pinMode(in_1, OUTPUT); 
pinMode(in_2, OUTPUT);
pinMode(in_3, OUTPUT);
pinMode(in_4, OUTPUT);
pinMode(en_1, OUTPUT);
pinMode(en_2, OUTPUT);
pinMode(LDR1, INPUT);
pinMode(LDR2, INPUT);
pinMode(LDR3, INPUT);
pinMode(LDR4, INPUT);
// calibrate the sensors
calibrate();
// set motor direction to forward
digitalWrite(in_1, HIGH);
digitalWrite(in_2,LOW);
digitalWrite(in_3, HIGH);
digitalWrite(in_4,LOW);
// set speed of both motors
analogWrite(en_1,left);
analogWrite(en_2,right);
}
void loop() {
   Serial.print(" LDR1:");

  Serial.println(); 
  
   Serial.print("LDR2:");

  Serial.println();
   Serial.print("LDR3:");

  Serial.println();
   Serial.print("LDR4:");

  Serial.println();
// make both motors same speed
left = startSpeed;
right = startSpeed;
// read the sensors and add the offsets
LDR1 = analogRead(0) + rightOffset;
Serial.print(LDR1);
LDR2 = analogRead(3);
Serial.print(LDR2);
LDR3 = analogRead(1);
Serial.print(LDR3);
LDR4 = analogRead(2) + leftOffset;
Serial.print(LDR4);
// if LDR1 is greater than the centre sensor + threshold turn right
if (LDR4 > (LDR2+threshhold)) {
left = startSpeed + rotate;
right = startSpeed - rotate;
}
// if LDR4 is greater than the centre sensor + threshold turn left
if (LDR1 > (LDR2+threshhold)) {
left = startSpeed - rotate;
right = startSpeed + rotate;
}
// send the speed values to the motors
analogWrite(en_1,left);
analogWrite(en_2,right);
}
