int button=4;
int led=1;
void setup() {
  // put your setup code here, to run once:
   pinMode(led,OUTPUT);
   pinMode(button,INPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  int ro=digitalRead(button);

if(ro){
//on
digitalWrite(led,1);
}
else{
  //off
  digitalWrite(led,0);
}
}
