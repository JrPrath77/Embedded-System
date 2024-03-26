#include <Servo.h>
Servo myServo;
int pos=0;
void setup() {
  // put your setup code here, to run once:
myServo.attach (9);
}

void loop() {
  // put your main code here, to run repeatedly:
for (int i=pos;i<=180;i++)
{
  myServo.write(i);
  delay(10);
}
delay(100);
for (int i=180;i>=pos;i--)
{
  myServo.write(i);
  delay(10);
}
}
