int led1=1;
int led2=3;
int led3=4;

void setup() {
  // put your setup code here, to run once:
  pinMode(led1,OUTPUT);
  pinMode(led2,OUTPUT);
  pinMode(led3,OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:

    digitalWrite(led1,1);
     digitalWrite(led2,0);
     digitalWrite(led3,0);
    delay(1000);

    digitalWrite(led2,1);
      digitalWrite(led1,0);
      digitalWrite(led3,0);
    delay(1000);
  
    digitalWrite(led3,1);
      digitalWrite(led2,0);
      digitalWrite(led1,0);
    delay(1000);
    

}
