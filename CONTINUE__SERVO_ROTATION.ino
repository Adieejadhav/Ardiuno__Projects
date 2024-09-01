
#include<Servo.h>

 // creating the object using inbuilt Servo named class
 Servo myservo;

void setup() {

  myservo.attach(9);

}

void loop() {


//Rotates the servo motor  from 0 degree to 180 degree
  for(a=0;a<=180;a++){
    myservo.write(a);
    delay(10);
  }

//Rotates the servo motor  from 180 degree to 0 degree  
  for(a=180;a>=0;a--){
    myservo.write(a);
    delay(10);
  }
  
}
