//Buttons
int b1=2;
int b2=3;
int b3=4;
//traffic light
int red=8;
int yello=9;
int green=10;

void setup() {
  // put your setup code here, to run once:
  pinMode(red,OUTPUT);
  pinMode(yello,OUTPUT);
  pinMode(green,OUTPUT);
  pinMode(b1,INPUT);
  pinMode(b1,INPUT);
  pinMode(b1,INPUT);
 Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
int ro1=digitalRead(b1);
int ro2=digitalRead(b2);
int ro3=digitalRead(b3);

Serial.print("B1: ");
Serial.print(ro1);

Serial.print("\t B2: ");
Serial.print(ro2);

Serial.print("\t B3: ");
Serial.print(ro3);

if(ro1==1 && ro2==1 && ro3==1){
  digitalWrite(red,0);
  digitalWrite(yello,0);
  digitalWrite(green,1);
  Serial.print("\t\t B1 B2 B3  On\n");
  delay(1000);
}
else if(ro1==1 && ro2==1){
  digitalWrite(red,0);
  digitalWrite(yello,1);
  digitalWrite(green,0);
  Serial.print("\t\tB1 B2  On\n");
  delay(1000);
}
else if(ro1==1){
  digitalWrite(red,1);
  digitalWrite(yello,0);
  digitalWrite(green,0);
  Serial.print("\t\t B1  On\n");
  delay(1000);
}
else{
  digitalWrite(red,0);
  digitalWrite(yello,0);
  digitalWrite(green,0);
  Serial.print("\t\t All Off\n");
  delay(1000);

}
}
