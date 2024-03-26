#define leftMotorSpeed 100
#define rightMotorSpeed 100
//Line Follow Sensor
int o1 = 2;
int o2 = 3;
int o3 = 4;
int o4 = 5;
int o5 = 6;

/* Motor Define
mo1,mo3 for forward rotation of motor
mo2,mo4 for reverrse rotation of motor  */
//right motor
int enLeftMotor=3;
int mo1=A2;
int mo2=A3;

//left motor
int enRightMotor=5;
int mo3=A4;
int mo4=A5; 

int O1,O2,O3,O4,O5;

void setup() {
  // put your setup code here, to run once:
  // increses frequnecy of analogWrite signal
  //below line is for lower speed at higher pwm value , it changes frequency of pwm signal on pin A0,A1
  //TCCR0B = TCCR0B & B11111000 | B00000010 ; 

pinMode(enLeftMotor,OUTPUT);
pinMode(mo1,OUTPUT);
pinMode(mo2,OUTPUT);

pinMode(enRightMotor,OUTPUT);
pinMode(mo3,OUTPUT);
pinMode(mo4,OUTPUT);

pinMode(o1,INPUT);
pinMode(o2,INPUT);
pinMode(o3,INPUT);
pinMode(o4,INPUT);
pinMode(o5,INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
 O1=digitalRead(o1);
 O2=digitalRead(o2);
 O3=digitalRead(o3);
 O4=digitalRead(o4);
 O5=digitalRead(o5);

line_follow();
delay(100);  // to give time to sensors take reading
}
void move_forward(){
  analogWrite(enLeftMotor,leftMotorSpeed);
  analogWrite(enRightMotor,rightMotorSpeed);
  digitalWrite(mo1,1);
  digitalWrite(mo2,0);
  digitalWrite(mo3,1);
  digitalWrite(mo4,0);
  delay(100);  
}

void stop(){
  digitalWrite(mo1,0);
  digitalWrite(mo2,0);
  digitalWrite(mo3,0);
  digitalWrite(mo4,0);
  delay(100);  
}

void turn_right(){
// soft right rotate right motor in reverse direction and left motor in forward direction
  digitalWrite(mo1,0);
  digitalWrite(mo2,0);
  digitalWrite(mo3,1); // left motor
  digitalWrite(mo4,0);

  analogWrite(enRightMotor, rightMotorSpeed);
  analogWrite(enLeftMotor, leftMotorSpeed);   
 delay(10);  
}

void slight_right(){
// soft right rotate right motor in reverse direction and left motor in forward direction
  digitalWrite(mo1,0);
  digitalWrite(mo2,0);
  digitalWrite(mo3,1); // left motor
  digitalWrite(mo4,0);

  analogWrite(enRightMotor, rightMotorSpeed);
  analogWrite(enLeftMotor, leftMotorSpeed);   
 delay(1);  
}

void turn_left(){
// soft right rotate right motor in reverse direction and left motor in forward direction
  digitalWrite(mo1,1); // right motor
  digitalWrite(mo2,0);
  digitalWrite(mo3,0);
  digitalWrite(mo4,0);

  analogWrite(enRightMotor, rightMotorSpeed);
  analogWrite(enLeftMotor, leftMotorSpeed);   
  delay(10);  
}
void slight_left(){
// soft right rotate right motor in reverse direction and left motor in forward direction
  digitalWrite(mo1,1); // right motor
  digitalWrite(mo2,0);
  digitalWrite(mo3,0);
  digitalWrite(mo4,0);

  analogWrite(enRightMotor, rightMotorSpeed);
  analogWrite(enLeftMotor, leftMotorSpeed);   
  delay(1);  
}

void line_follow(){
 // for black colour our sensor is low ...(zero)
 // and for whit its high ..(1) 
     if(O1==1 && O2==1 && O3==1 && O4==1 && O5==1){
        stop();
     }
    if(O1==0 && O2==0 && O3==0 && O4==0 && O5==0){
        move_forward();
     }

    // ----------------------left------------------------

     else if(O1==0 && O2==0 && O3==0 && O4==0 && O5==1){
        slight_left();
     }
     else if(O1==0 && O2==0 && O3==0 && O4==1 && O5==1){
        slight_left();
     }   
     else if(O1==0 && O2==0 && O3==1 && O4==1 && O5==1){
        slight_left();
     } 
     else if(O1==0 && O2==1 && O3==1 && O4==1 && O5==1){
        turn_left();
     }           
      
      // ----------------------Right------------------------

      if(O1==1 && O2==0 && O3==0 && O4==0 && O5==0){
        slight_right();
      }
      else if(O1==1 && O2==1 && O3==0 && O4==0 && O5==0){
        slight_right();
      }
       else if(O1==1 && O2==1 && O3==1 && O4==0 && O5==0){
        slight_right();
      }
       else if(O1==1 && O2==1 && O3==1 && O4==0 && O5==0){
        turn_right();
      }
      

      }
