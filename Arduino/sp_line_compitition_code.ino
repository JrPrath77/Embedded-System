#include <EEPROM.h>

 int pwm=160;
 int tap=0;

void setup() {
  Serial.begin(9600);           // set up Serial library at 9600 bps
 
    // sensor 
    pinMode(A0,INPUT);
  pinMode(A1,INPUT);
  pinMode(A2,INPUT);
    pinMode(A3,INPUT);
     pinMode(A4,INPUT);
     pinMode(A5,INPUT);
     
     //tap
     pinMode(A8,INPUT);
   
   // motor
    pinMode(9,OUTPUT);
   pinMode(10,OUTPUT);
    pinMode(11,OUTPUT);
     pinMode(12,OUTPUT);
     pinMode(7,OUTPUT);
     pinMode(8,OUTPUT);

//forward(); //this function is check the wiring 
//tright();
//tleft();


track1();
stay();     //this is main calling remember this shit

stay2();


}

void stay()
{
  while(1){
  tap =digitalRead(A8);
  Serial.println(tap);
          if(tap==1)
          {
            Serial.println("track2");
            
            delay(2000);
                    
            track2();
             break;
             
            }
            else{
              brake();
              continue;
              
              
              }
   
  }
  
  }
  void stay2()
{
  while(1){
  tap =digitalRead(A8);
  Serial.println(tap);
          if(tap==1)
          {
            Serial.println("track3");
            
            delay(2000);
                    
            track3();
             break;
             
            }
            else{
              brake();
              continue;
              
              
              }
   
  }
  
  }
/*void staytwo()
{
  while(1){
  tap =digitalRead(A10);
  Serial.println(tap);
          if(tap==1)
          {
            delay(2000);
                    
              EEPROM.write(8,1);
             break;
             
            }
            else{
              brake();
              continue;
              
              
              }
   
  }
  
  }
*/
  
/* void stayy()
{
  
   while(1){
 
   delay(4000);
   int tap =digitalRead(A8);
   int tapp =digitalRead(A10);
          if(tap==1)
          {
             Serial.println("task=1");
             track2();
              EEPROM.write(9,1);
               brake();
            break;
             
            }
            if(tapp==1){
              Serial.println("task=2");
                track_2();
                EEPROM.write(9,2);
              brake();
             break;
              
              
              }
        continue;     
   
  }
}
*/
void leftside()
{
  
  }

void rightside()
{
  
}

void track1()
{

goforward();
go();
tleft();
  goforward();
  go();
  tright();
  goforward();
  go();
  
  tleft();
  goforward();
  go();
 goforward();
 go();
  tright();
  goforward();
  go();
  
  tright();
  goforward();
  go();
  tleft();

  //check below===================
  goforward();
  go();
  tright();
  goforward();
  go();
  goforward();
  tright();
  goforward();
  //^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
  
  go();
  tleft();
  goforward();
  go();
  tright();
  goforward();
  go();
  tleft();
  goforward();
  // tleft();
 
}


void track2()
{
  tright();
  goforward();
  go();
  goforward();
go();
goforward();
go();
//tright();
goforward();
go();
tright();
goforward();
go();
tleft();
goforward();
go();
tleft();
goforward();
go();
tright();
goforward();
go();
goforward();
  
}


void track_2()
{
  tright();
  goforward();
  go();
  tright();
  goforward();
  go();
  tleft();
  goforward();
  go();
  tright();
  goforward();
  go();
  goforward();
  go();
  goforward();
  go();
  tright();
  goforward();
  go();
  tleft();
  goforward();
  go();
  tleft();
  goforward();
  go();
  goforward();
  go();
  tright();
  goforward();
  go();
  tleft();
  goforward();
  go();
  tright();
  gof();
  
}

void track3()
{
//tright();
go();
  goforward();
go();
goforward();
go();
tleft();
goforward();
go();
tright();
goforward();
go();
tright();
goforward();
go();
goforward();
go();
}



void forward()
{
 analogWrite(9,pwm);
analogWrite(11,pwm);
digitalWrite(10,LOW);
digitalWrite(12,LOW);
digitalWrite(7,HIGH);
digitalWrite(8,HIGH);
   
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
   digitalWrite(9,LOW);
analogWrite(11,pwm);
digitalWrite(10,LOW);
digitalWrite(12,LOW);
 digitalWrite(7,HIGH);
digitalWrite(8,LOW);
 delay(10);
}

void left()
{
  digitalWrite(9,LOW);
analogWrite(11,pwm);
analogWrite(10,pwm);
digitalWrite(12,LOW);
 digitalWrite(7,HIGH);
digitalWrite(8,HIGH);
 delay(10);
  
}


void soft_right()
{
 analogWrite(9,pwm);
digitalWrite(11,LOW);
digitalWrite(10,LOW);
digitalWrite(12,LOW);
digitalWrite(7,LOW);
digitalWrite(8,HIGH);
 delay(10);
}


void right()
{
  analogWrite(9,pwm);
digitalWrite(11,LOW);
digitalWrite(10,LOW);
analogWrite(12,pwm);
digitalWrite(7,HIGH);
digitalWrite(8,HIGH);
 delay(10);
}




void backward()
{
   digitalWrite(9,LOW);
digitalWrite(11,LOW);
analogWrite(10,pwm);
analogWrite(12,pwm);
 digitalWrite(7,HIGH);
digitalWrite(8,HIGH);
 delay(10);
}

void brake()
{
   digitalWrite(9,LOW);
digitalWrite(11,LOW);
digitalWrite(10,LOW);
digitalWrite(12,LOW);
 delay(10);
digitalWrite(7,LOW);
digitalWrite(8,LOW);
}
void goforward()
{
      while(1)
      {
                   if(digitalRead(A0)==LOW && digitalRead(A1)==HIGH && digitalRead(A2)==HIGH && digitalRead(A3)==LOW)
                    {
                  forward();
                    }
                  
                   else if(digitalRead(A0)==LOW && digitalRead(A1)==HIGH && digitalRead(A2)==LOW && digitalRead(A3)==LOW)
                    {
                  forward();
                    }
                  
                      if(digitalRead(A0)==LOW && digitalRead(A1)==LOW && digitalRead(A2)==HIGH && digitalRead(A3)==LOW)
                    {
                  forward();
                    }
                    
                   /* if(digitalRead(A0)==HIGH && digitalRead(A1)==HIGH && digitalRead(A2)==HIGH && digitalRead(A3)==LOW && digitalRead(A4)==LOW)
                    {
                  forward();
                    }
                  
                      if(digitalRead(A0)==LOW && digitalRead(A1)==LOW && digitalRead(A2)==HIGH && digitalRead(A3)==HIGH && digitalRead(A4)==HIGH)
                    {
                  forward();
                    }*/
                  
                      if(digitalRead(A0)==LOW && digitalRead(A1)==LOW && digitalRead(A2)==HIGH && digitalRead(A3)==HIGH)
                    {
                    soft_right();
                    }
                  
                      if(digitalRead(A0)==HIGH && digitalRead(A1)==HIGH && digitalRead(A2)==LOW && digitalRead(A3)==LOW)
                    {
                  soft_left();
                    }
                  
                  
                      if(digitalRead(A0)==LOW && digitalRead(A1)==LOW && digitalRead(A2)==LOW && digitalRead(A3)==HIGH)                    {
                  right();
                  
                    }
                  
                      if(digitalRead(A0)==HIGH && digitalRead(A1)==LOW && digitalRead(A2)==LOW && digitalRead(A3)==LOW)
                    {
                  left();
                    }




                  
                    if(digitalRead(A4)==HIGH && digitalRead(A1)==HIGH && digitalRead(A2)==HIGH && digitalRead(A3)==HIGH)
                    {
                       brake();
                   break;
                  
                    }
                    if(digitalRead(A0)==LOW && digitalRead(A1)==LOW && digitalRead(A2)==LOW && digitalRead(A3)==LOW)
                    {
                       //delay(15-0);
                       brake();
                   break;
                  
                    }
                    if(digitalRead(A4)==LOW && digitalRead(A0)==LOW && digitalRead(A3)==HIGH &&digitalRead(A5)==HIGH)
                    {
                       //delay(15-0);
                       brake();
                   break;
                  
                    }
                    if(digitalRead(A4)==HIGH && digitalRead(A0)==HIGH && digitalRead(A4)==LOW && digitalRead(A5)==LOW)
                    {
                       //delay(15-0);
                       brake();
                   break;
                  
                    }
                       if(digitalRead(A4)==HIGH && digitalRead(A0)==HIGH && digitalRead(A1)==HIGH && digitalRead(A5)==LOW)
                    {
                       //delay(15-0);
                       brake();
                   break;
                  
                    }
                    
                  
      }
}


void gobackward()
{
  while(1)
  {
       if(digitalRead(A0)==LOW && digitalRead(A1)==LOW && digitalRead(A2)==HIGH && digitalRead(A3)==LOW && digitalRead(A4)==LOW)
                    {
                  backward();
                    }
                  
                      if(digitalRead(A0)==LOW && digitalRead(A1)==HIGH && digitalRead(A2)==HIGH && digitalRead(A3)==LOW && digitalRead(A4)==LOW)
                    {
                  forward();
                    }
                    
                  
                     // if(digitalRead(A0)==LOW && digitalRead(A1)==LOW && digitalRead(A2)==HIGH && digitalRead(A3)==HIGH && digitalRead(A4)==LOW)
                    //{
                  //forward();
                   // }
                     if(digitalRead(A0)==LOW && digitalRead(A1)==HIGH && digitalRead(A2)==HIGH && digitalRead(A3)==HIGH && digitalRead(A4)==LOW)
                    {
                  backward();
                    }
                  
                      if(digitalRead(A0)==LOW && digitalRead(A1)==LOW && digitalRead(A2)==LOW && digitalRead(A3)==HIGH && digitalRead(A4)==HIGH)
                    {
                    soft_right();
                    }
                  
                      if(digitalRead(A0)==HIGH && digitalRead(A1)==HIGH && digitalRead(A2)==LOW && digitalRead(A3)==LOW && digitalRead(A4)==LOW)
                    {
                  soft_left();
                    }
                  
                  
                      if(digitalRead(A0)==LOW && digitalRead(A1)==LOW && digitalRead(A2)==LOW && digitalRead(A3)==LOW && digitalRead(A4)==HIGH)                    {
                  right();
                  
                    }
                  
                      if(digitalRead(A0)==HIGH && digitalRead(A1)==LOW && digitalRead(A2)==LOW && digitalRead(A3)==LOW && digitalRead(A4)==LOW)
                    {
                  left();
                    }
                  
                    if(digitalRead(A0)==HIGH && digitalRead(A1)==HIGH && digitalRead(A2)==HIGH && digitalRead(A3)==HIGH && digitalRead(A4)==HIGH)
                    {
                       brake();
                   break;
                  
                    }
                  
                  if(digitalRead(A0)==LOW && digitalRead(A1)==LOW && digitalRead(A2)==LOW && digitalRead(A3)==LOW && digitalRead(A4)==LOW)
                  {
                    //delay(15-0);
                   brake();
                   break;
                  
                  }
                     if(digitalRead(A0)==LOW && digitalRead(A1)==LOW && digitalRead(A2)==LOW && digitalRead(A3)==LOW)
                    {
                  forward();
                    }
  }
}


void tright()
{
  right();
  delay(100);
  brake();
  
  while(1)
  {
   right(); 
   if(digitalRead(A0)==LOW && digitalRead(A1)==LOW && digitalRead(A2)==HIGH && digitalRead(A3)==LOW)
  {
  
  brake();
  break;
  }
}
}

void tsoft_right()
{
  soft_right();
  delay(300);
  brake();
  
  while(1)
  {
   soft_right(); 
   if(digitalRead(A0)==LOW && digitalRead(A1)==LOW && digitalRead(A2)==LOW && digitalRead(A3)==HIGH && digitalRead(A4)==LOW)
  {
  
  brake();
  break;
  }
}
}


void tleft()
{
  left();
  delay(100);
  brake();
  
  while(1)
  {
  left();
  if(digitalRead(A0)==LOW && digitalRead(A1)==HIGH && digitalRead(A2)==LOW && digitalRead(A3)==LOW)
  {
    
    brake();
    break;
  }
}

}

void tsoft_left()
{
  soft_left();
  delay(300);
  brake();
  
  while(1)
  {
  soft_left();
  if(digitalRead(A0)==LOW && digitalRead(A1)==HIGH && digitalRead(A2)==LOW && digitalRead(A3)==LOW && digitalRead(A4)==LOW)
  {
    
    brake();
    break;
  }
}

}

  
int i=0;  

void loop()
{
  
}
