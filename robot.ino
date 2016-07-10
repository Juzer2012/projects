int in_1 = 8;        
int in_2 = 12;
int in_3 = 4;
int in_4 = 7;
int en_1 = 3;
int en_2 = 9;

// declaring Sensor Pins.
int LeftSensor = A1;
int RightSensor = A0; 
int L_sensor_val = 0; // To store value from sensors. 
int R_sensor_val = 0; 

int threshold = 200; // Threshold value to distinguish black and white. 

void setup()
{   // setting up shield. 
    pinMode(in_1, OUTPUT);    
    pinMode(in_2, OUTPUT);
    pinMode(in_3, OUTPUT);
    pinMode(in_4, OUTPUT);
    pinMode(en_1, OUTPUT);
    pinMode(en_2, OUTPUT); 
     analogWrite(en_1,255);
     analogWrite(en_2,255);
     forward(); // Default movement is forward.
}

void loop()
{
L_sensor_val =  analogRead(LeftSensor);   // Reading Left sensor data
R_sensor_val =  analogRead(RightSensor);  // Reading Right sensor data


  if(L_sensor_val<threshold && R_sensor_val>threshold) {  // testing for left turn
    while (L_sensor_val<threshold && R_sensor_val>threshold){
      turn_left();  
      L_sensor_val =  analogRead(LeftSensor);
      R_sensor_val =  analogRead(RightSensor);
    }
  }
  else if(L_sensor_val>threshold && R_sensor_val<threshold){  // tesing for right turn
    while (L_sensor_val>threshold && R_sensor_val<threshold){
      turn_right();
      L_sensor_val =  analogRead(LeftSensor);
      R_sensor_val =  analogRead(RightSensor);
    }
 }

}

void forward(void){  // function for forward movement. 
  digitalWrite(in_1,HIGH); // RIGHT MOTOR
  digitalWrite(in_2,LOW);
  
  digitalWrite(in_3,HIGH); // LEFT MOTOR
  digitalWrite(in_4,LOW);
}

void backward(void){   // function for forward movement. 

  digitalWrite(in_1,LOW);// RIGHT MOTOR
  digitalWrite(in_2,HIGH);
  analogWrite(en_1,100);
  
  digitalWrite(in_3,LOW); // LEFT MOTOR
  digitalWrite(in_4,HIGH);
  analogWrite(en_2,100); 

}
void turn_left(void){   // function for left turn.
  
  digitalWrite(in_1,HIGH); // RIGHT MOTOR
  digitalWrite(in_2,LOW);
  analogWrite(en_1,100);

  digitalWrite(in_3,LOW); // LEFT MOTOR
  digitalWrite(in_4,HIGH);
  analogWrite(en_2,100);
    
}

void turn_right(void){   // function for Right turn. 

  digitalWrite(in_1,LOW);// RIGHT MOTOR
  digitalWrite(in_2,HIGH);
  analogWrite(en_1,100);
  
  digitalWrite(in_3,LOW); // LEFT MOTOR
  digitalWrite(in_4,HIGH);
  analogWrite(en_2,100);   
}

//void halt(void){        // function for stopping robot. 
  
  //digitalWrite(in_1,HIGH);// RIGHT MOTOR
  //digitalWrite(in_2,HIGH);
  
  //digitalWrite(in_3,HIGH); // LEFT MOTOR
  //digitalWrite(in_4,HIGH);
         


