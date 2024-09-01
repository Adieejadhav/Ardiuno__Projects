
#include<Servo.h>

int triggerpin=12;
int echopin=10;
int duration=0;
int distance=0;
int servo_pin=9;
int distance_threshold=10;

 Servo myservo;

void setup() {
// put your setup code here, to run once:
  pinMode(triggerpin,OUTPUT);
  pinMode(echopin,INPUT);

  myservo.attach(servo_pin);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
// creates the pulse through ultrsonic sensor
  digitalWrite(triggerpin,LOW);
  delayMicroseconds(2);

  digitalWrite(triggerpin,HIGH);
  delayMicroseconds(10);
  delay(100);

  digitalWrite(triggerpin,LOW);

//calculates teh distance
  duration=pulseIn(echopin,HIGH);
  distance=(duration*0.0343)/2;

//if distance goes less than threshould distance then toll gate gets up
  if(distance<distance_threshold){
    myservo.write(90);
  }else{
    myservo.write(0);
  }
  
  Serial.println(distance);

}
