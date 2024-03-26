//RGB colour system
// potentiometer
int p1=A1;
int p2=A2;
int p3=A3;
int red=A6;
int green=A5;
int blue=A4;


void setup() {
  // put your setup code here, to run once:
  pinMode(p1,INPUT);
  pinMode(p2,INPUT);
  pinMode(p3,INPUT);

  pinMode(red,OUTPUT);
  pinMode(green,OUTPUT);
  pinMode(blue,OUTPUT);
 
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
    int ro1,ro2,ro3;
    ro1=analogRead(p1);
    ro1=map(ro1,0,1023,0,255);
    analogWrite(red,ro1);

    ro2=analogRead(p2);
    ro2=map(ro2,0,1023,0,255);
    analogWrite(green,ro2);

    ro3=analogRead(p3);
   ro3=map(ro3,0,1023,0,255);
   analogWrite(blue,ro3);


}
/*   The line `analogWrite(red,ro1);` in the provided Arduino sketch is responsible for controlling the intensity of the red component in an RGB LED based on the value read from the potentiometer connected to pin A1. 

Breaking it down:
- `analogWrite(red,ro1);` is instructing the Arduino to write the value of `ro1` to the pin `red` using the PWM (Pulse Width Modulation) technique. 
- `red` is the pin connected to the red component of the RGB LED.
- `ro1` is the value read from potentiometer p1 after mapping it from the 10-bit range (0-1023) to an 8-bit range (0-255) using the `map()` function. This value ultimately represents the intensity of the red component of the LED.

This code essentially allows you to control the intensity of each color component of the RGB LED (red, green, and blue)
 independently based on the readings from the three potentiometers. Each potentiometer allows you to adjust the intensity of the corresponding color in real-time, creating a customized color output 
 from the RGB LED based on the settings of the potentiometers.  

 */
