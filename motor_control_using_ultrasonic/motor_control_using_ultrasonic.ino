int tonePin = 7; 
int trigPin = 9;   
int echoPin = 10; 
int duration;
int distance;
int E1=3;
int I1=4;
int I2=5;
void setup() {
Serial.begin (9600);
  
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(tonePin, OUTPUT);
  pinMode(E1, OUTPUT);
  pinMode(I1, OUTPUT);
  pinMode(I2, OUTPUT);

}

void loop() {
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration/2) / 29.1;
  

  if(distance < 100 || distance >50){
  Serial.print("Obstacle is in:  ");
  Serial.print(distance);
  Serial.println(" cm; ");
  Serial.println("Warning!");
  analogWrite(E1, 100);  // Run in half speed
    digitalWrite(I1, HIGH);
  digitalWrite(I2, LOW);
  digitalWrite(tonePin, HIGH);
  delay(5000);
  digitalWrite(tonePin, LOW);
  delay(10);
  
  }
      if(distance < 50){
      Serial.print("Obstacle is in:  ");
      Serial.print(distance);
      Serial.println(" cm; ");
      Serial.println("Warning!");
     analogWrite(E1, 200);  // Run in high speed
       digitalWrite(I1, HIGH);
  digitalWrite(I2, LOW);
     digitalWrite(tonePin, HIGH);
  delay(3000);
  digitalWrite(tonePin, LOW);
  delay(10);

    }
        else{
      Serial.print("Obstacle is in:  ");
      Serial.print(distance);
      Serial.print(" cm; ");
      Serial.println("You are safe!");
      analogWrite(E1, 50);  // Run in low speed
        digitalWrite(I1, HIGH);
  digitalWrite(I2, LOW);
 digitalWrite(tonePin, HIGH);
  delay(2000);
  digitalWrite(tonePin, LOW);
  delay(10);
    }
    delay(1000);



 }



