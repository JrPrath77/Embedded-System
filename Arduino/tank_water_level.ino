//task 1
//Tank water level  without using sensors(use buttons inseted of sensors)
//bottom level - display -> bottom level, green led on;
// middle level - middle level , yello led on;
// top level-   -> top level , red led on;

//buttons
int top=2;
int bottom=4;
int middle=3;
//LED's
int  red=8;
int yello=9;
int green=10;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  // INPUT pins
  pinMode(top,INPUT);
  pinMode(middle,INPUT);
  pinMode(bottom,INPUT);

//Output pins
pinMode(red,OUTPUT);
pinMode(yello,OUTPUT);
pinMode(green,OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  int ro1=digitalRead(top);
  int ro2=digitalRead(middle);
  int ro3=digitalRead(bottom);

if(ro1==1 && ro2==1 && ro3==1){
  digitalWrite(red,1);
  digitalWrite(yello,0);
  digitalWrite(green,0);
  Serial.println("Top level reached");
  tone (A15,1000,500);
  delay(1000);
}
else if(ro1==0 && ro2==1 && ro3==1){
  digitalWrite(red,0);
  digitalWrite(yello,1);
  digitalWrite(green,0);
  Serial.println("Middle level reached");

  delay(1000);
}
else if(ro1==0 && ro2==0 && ro3==1){
  digitalWrite(red,0);
  digitalWrite(yello,0);
  digitalWrite(green,1);
  Serial.print("Bottom level reached");
  delay(1000);
}
else{
  
  digitalWrite(red,0);
  digitalWrite(yello,0);
  digitalWrite(green,0);
  Serial.println("MOTOR OFF");
  delay(1000);
}
}
