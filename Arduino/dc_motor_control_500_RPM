// voltage
// rpm
// torque
//geared(1.bear motor 2. johsan motor)/brushless motor

// Q. forward  5sec
//   stop 
//   backward  5sec

int s1=2,s2=3,s3=4,s4=5;
int enable1=A5,enable2=A6;


void setup() {
  // put your setup code here, to run once:
  pinMode(s1,OUTPUT);
  pinMode(s2,OUTPUT);
  pinMode(s3,OUTPUT);
  pinMode(s4,OUTPUT);
  pinMode(enable1,OUTPUT);
  pinMode(enable2,OUTPUT);
  Serial.begin(9600);
}

void forward()
{
// motor 1
digitalWrite (s1,1);
digitalWrite (s2,0);
// motor 1
digitalWrite (s3,1);
digitalWrite (s4,0);
}
void rv()
{
  // motor 1
digitalWrite (s1,0);
digitalWrite (s2,1);
//motor 2
digitalWrite (s3,0);
digitalWrite (s4,1);
}

void stop()
{   // motor 1
digitalWrite (s1,0);
digitalWrite (s2,0);
  // motor 2
digitalWrite (s3,0);
digitalWrite (s4,0);
}

void control(){
  
  for(int i=1; i<=255; i++){
    analogWrite(enable1,i);
    Serial.println("MOTOR1 RPM:");
    Serial.print(i);

    analogWrite(enable2,i);
    Serial.println("MOTOR2 RPM:");
    Serial.print(i);
    delay(100);
  }
}
void loop() {
  // put your main code here, to run repeatedly:
  control();
  forward();
  delay(5000);
    stop();
    delay(2000);
  
  control();
  rv();
  delay(5000);
    stop();
    delay(2000);



}

