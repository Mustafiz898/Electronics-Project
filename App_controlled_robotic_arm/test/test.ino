#include<Servo.h>
#define base 9
#define shoulder 10
#define elbow 11
#define gripper 12

Servo s1;
Servo s2;
Servo s3;
Servo s4;

void setup()
{
Serial.begin(9600);
s1.attach(base);
s2.attach(shoulder);
s3.attach(elbow);
s4.attach(gripper);

}
void loop()
{
  
s1.write(0);
delay(1000);
s3.write(0);
delay(1000);
s1.write(100);
delay(1000);
s3.write(100);
delay(1000);
s4.write(180);
delay(1000);
s4.write(0);

delay(1000);
s3.write(0);
delay(1000);




}