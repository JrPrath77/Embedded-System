//relay - electronic switch(on/off)
int b1=4;
int b2=5;
int b3=6;
int b4=7;

int indicator_bulb_1=8;
int indicator_bulb_2=9;
int indicator_bulb_3=10;

void setup() {
  // put your setup code here, to run once:
  pinMode(b1,INPUT);
  pinMode(b2,INPUT);
  pinMode(b3,INPUT);
  pinMode(b4,INPUT);

  pinMode(indicator_bulb_1,OUTPUT);
  pinMode(indicator_bulb_2,OUTPUT);
  pinMode(indicator_bulb_3,OUTPUT);

  digitalWrite(indicator_bulb_1,0);
digitalWrite(indicator_bulb_2,0);
digitalWrite(indicator_bulb_3,0);

  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
int ro1,ro2,ro3,ro4;

  ro1=digitalRead(b1);
  ro2=digitalRead(b2);
  ro3=digitalRead(b3);
  ro4=digitalRead(b4);



  if(ro1==1){
    digitalWrite(indicator_bulb_1,1);
  }
  else{
      digitalWrite(indicator_bulb_1,0);

  }
  if(ro2==1){
    digitalWrite(indicator_bulb_2,1);
  }
  else{
      digitalWrite(indicator_bulb_2,0);
  }
  if(ro3==1){
     digitalWrite(indicator_bulb_3,1);
     
  }
  else{
    digitalWrite(indicator_bulb_3,0);
  }
  if(ro4==1){
    digitalWrite(indicator_bulb_1,0);
    digitalWrite(indicator_bulb_2,0);
    digitalWrite(indicator_bulb_3,0);
  }

}
