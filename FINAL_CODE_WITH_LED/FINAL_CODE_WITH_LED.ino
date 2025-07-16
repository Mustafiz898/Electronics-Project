#include <SoftwareSerial.h>

#include <Servo.h> 
Servo base, shoulder, elbow, gripper;

int bluetoothTx = 0;
int bluetoothRx = 1;

SoftwareSerial bluetooth(bluetoothTx, bluetoothRx);

void setup()
{
  base.attach(9);
  shoulder.attach(10);
  elbow.attach(11);
  gripper.attach(12);
  pinMode(7,OUTPUT);
  pinMode(6,OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(8,OUTPUT);
  //Setup usb serial connection to computer
  Serial.begin(9600);

  //Setup Bluetooth serial connection to android
  bluetooth.begin(9600);
}

void loop()
{
  //Read from bluetooth and write to usb serial
  if(bluetooth.available()>= 2 )
  {
    unsigned int servopos = bluetooth.read();
    unsigned int servopos1 = bluetooth.read();
    unsigned int realservo = (servopos1 *256) + servopos; 
    Serial.println(realservo); 
    
    if (realservo >= 1000 && realservo <1180){
    int servo1 = realservo;
    servo1 = map(servo1, 1000,1180,0,180);
    base.write(servo1);
    if(realservo>1100){
    digitalWrite(8,HIGH);}
    else{digitalWrite(8,LOW);}
    Serial.println("BASE ON");
    delay(10);

    }
    
    if (realservo >=2000 && realservo <2180){
      int servo2 = realservo;
      servo2 = map(servo2,2000,2180,0,180);
      shoulder.write(servo2);
      if(realservo>2100){
      digitalWrite(7,HIGH);}
      else{digitalWrite(7,LOW);}
      Serial.println("SHOULDER On");
      delay(10);
      
    }
    
    if (realservo >=3000 && realservo < 3180){
      int servo3 = realservo;
      servo3 = map(servo3, 3000, 3180,0,180);
      elbow.write(servo3);
      if(realservo>3100){
      digitalWrite(6,HIGH);}
      else{digitalWrite(6,LOW);}
      Serial.println("ELBOW On");
      delay(10);
    }
    if (realservo >=4000 && realservo < 4180){
      int servo4 = realservo;
      servo4 = map(servo4, 4000, 4180,0,180);
      gripper.write(servo4);
      if(realservo>4100){
      digitalWrite(5,HIGH);}
      else{digitalWrite(5,LOW);}
      Serial.println("GRIPPER On");
      delay(10);
    }
    

    }
 
  }



