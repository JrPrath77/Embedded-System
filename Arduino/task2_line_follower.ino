//Line Follow Sensor
int o1 = 8;
int o2 = 9;
int o3 = 10;
int o4 = 11;
int o5 = 12;

//Motor Define
int en1=A0;
int en2=A1;
int mo1=A2;
int mo2=A3;
int mo3=A4;
int mo4=A5; 

int pwm=180;

void setup() {
  Serial.begin(9600);

  //Motor Pin Define
  pinMode(mo1,OUTPUT);
  pinMode(mo2,OUTPUT);
  pinMode(mo3,OUTPUT);
  pinMode(mo4,OUTPUT);
  pinMode(en1,INPUT);
  pinMode(en2,INPUT);

  //Sensor Pin Mode
  pinMode(o1,INPUT);
  pinMode(o2,INPUT);
  pinMode(o3,INPUT);
  pinMode(o4,INPUT);
  pinMode(o5,INPUT);  

}

void loop() {
  //forward();
  //left();
  Serial.print("o1: ");
  Serial.print(digitalRead(o1));
  Serial.println();
  //delay(100);
  goforward();
}

//_______________________
void forward()
{
  analogWrite(en1,pwm);
  analogWrite(en2,pwm);
  digitalWrite(mo1,0);
  digitalWrite(mo2,1);
  digitalWrite(mo3,0);
  digitalWrite(mo4,1);
  delay(10);
  }
void go()
{
  
  forward();
  delay(100);
  brake();
  
  }

void gof()
{
  
  forward();
  delay(600);
  brake();
  
  }


void sgo()
{
     
  forward();
  delay(200);
  brake();
  }

void back()
{
  
  backward();
  delay(100);
  brake();
  }

void soft_left()
{
  
  //delay(1);
  analogWrite(en1,pwm);
  analogWrite(en2,pwm);
  digitalWrite(mo1,0);
  digitalWrite(mo2,1);
  digitalWrite(mo3,0);
  digitalWrite(mo4,0);

  delay(1);
  brake();
  }

void left()
{
  
  analogWrite(en1,pwm);
  analogWrite(en2,pwm);
  digitalWrite(mo1,0);
  digitalWrite(mo2,1);//Right Motor
  digitalWrite(mo3,0);
  digitalWrite(mo4,0);
  delay(10);
  brake();
  }


void soft_right()
{
  
  analogWrite(en1,pwm);
  analogWrite(en2,pwm);
  digitalWrite(mo1,0);
  digitalWrite(mo2,0);
  digitalWrite(mo3,0);
  digitalWrite(mo4,1);
  delay(1);
  brake();
  }


void right()
{
  analogWrite(en1,pwm);
  analogWrite(en2,pwm);
  digitalWrite(mo1,0);
  digitalWrite(mo2,0);
  digitalWrite(mo3,0);
  digitalWrite(mo4,1);
  delay(10);
  brake();
  }




void backward()
{
  analogWrite(en1,pwm);
  analogWrite(en2,pwm);
  digitalWrite(mo1,1);
  digitalWrite(mo2,0);
  digitalWrite(mo3,1);
  digitalWrite(mo4,0);
  delay(10);
}

void brake()
{
  analogWrite(en1,pwm);
  analogWrite(en2,pwm);
  digitalWrite(mo1,0);
  digitalWrite(mo2,0);
  digitalWrite(mo3,0);
  digitalWrite(mo4,0);
}
void goforward()
{
      while(1)
      {
                   if(digitalRead(o1)==1 && digitalRead(o2)==1 && digitalRead(o3)==1 && digitalRead(o4)==1 && digitalRead(o5)==1)
                    {
                      brake();
                    }         
                   
                   if(digitalRead(o1)==0 && digitalRead(o2)==0 && digitalRead(o3)==0 && digitalRead(o4)==0 && digitalRead(o5)==0)
                    {
                      forward();
                    }

                    else if(digitalRead(o1)==0 && digitalRead(o2)==0 && digitalRead(o3)==0 && digitalRead(o4)==0 && digitalRead(o5)==1)
                    {
                      soft_left();
                    }
                   else if(digitalRead(o1)==0 && digitalRead(o2)==0 && digitalRead(o3)==0 && digitalRead(o4)==1 && digitalRead(o5)==1)
                    {
                      soft_left();
                    }
                  
                    else if(digitalRead(o1)==0 && digitalRead(o2)==0 && digitalRead(o3)==1 && digitalRead(o4)==1 && digitalRead(o5)==1)
                    {
                      soft_left();
                    }
                    else if(digitalRead(o1)==0 && digitalRead(o2)==1 && digitalRead(o3)==1 && digitalRead(o4)==1 && digitalRead(o5)==1)
                    {
                      left();
                    }
                      //Right
                    if(digitalRead(o1)==1 && digitalRead(o2)==0 && digitalRead(o3)==0 && digitalRead(o4)==0 && digitalRead(o5)==0)
                    {
                      soft_right();
                    }

                    else if(digitalRead(o1)==1 && digitalRead(o2)==1 && digitalRead(o3)==0 && digitalRead(o4)==0 && digitalRead(o5)==0)
                    {
                      soft_right();
                    }
                  
                    else if(digitalRead(o1)==1 && digitalRead(o2)==1 && digitalRead(o3)==1 && digitalRead(o4)==0 && digitalRead(o5)==0)
                    {
                      soft_right();
                    }
                  
                    else if(digitalRead(o1)==1 && digitalRead(o2)==1 && digitalRead(o3)==1 && digitalRead(o4)==1 && digitalRead(o5)==0)
                    {
                      right();
                    }            
                  
      }
}
