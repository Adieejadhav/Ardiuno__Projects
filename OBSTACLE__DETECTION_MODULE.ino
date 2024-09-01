//Including liabrary for the functioning of servo motor
#include <Servo.h>

//Defining the pins 
#define pin13 13
#define pin12 12
#define pin8 8
#define pin7 7
#define pinA5 5
#define pinA6 6
#define serPin 9
#define TRIGGER_PIN 11
#define ECHO_PIN 10



//Declaring the variables for storing distances
int default_Distance = 0;
int distance_L = 0;
int distance_R = 0;
int value;
const int potPin = A0; 

//Creating object using inbuilt 'Servo' class
Servo myservo;


void setup() {

 //setting pins as OUTPUT for roatating DC motors 
  pinMode(pin13, OUTPUT);
  pinMode(pin12, OUTPUT);
  pinMode(pin8, OUTPUT);
  pinMode(pin7, OUTPUT);
  pinMode(potPin, INPUT);

   pinMode(potPin, INPUT); 

 //Used for controllling the speed of 2 DC motors
  pinMode(pinA5, OUTPUT);
  pinMode(pinA6, OUTPUT);

 // Used for sensor functioning  
  pinMode(TRIGGER_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);

 //attaching pin for sending analog values to servo motor
  myservo.attach(serPin);
  Serial.begin(9600);
}

    int calculateDistance() {

      int duration = 0;
      float distance;

      //Generate Pulse
      digitalWrite(TRIGGER_PIN, LOW);
      delayMicroseconds(2);

      digitalWrite(TRIGGER_PIN, HIGH);
      delayMicroseconds(10);
      delay(100);

      digitalWrite(TRIGGER_PIN, LOW);

      //Calculate Diastance
      duration = pulseIn(ECHO_PIN, HIGH);
      distance = (duration * 0.0343) / 2;

      return distance;
    }

    //Function for Forward direction
    void fd() {
      digitalWrite(pin13, LOW);
      digitalWrite(pin12, HIGH);

      digitalWrite(pin7, LOW);
      digitalWrite(pin8, HIGH);
    }

    //Function for Backward direction
    void bd() {
      digitalWrite(pin13, HIGH);
      digitalWrite(pin12, LOW);

      digitalWrite(pin7, HIGH);
      digitalWrite(pin8, LOW);
    }

    //Function for Left direction
    void lt() {
      digitalWrite(pin13, LOW);
      digitalWrite(pin12, HIGH);

      digitalWrite(pin7, HIGH);
      digitalWrite(pin8, LOW);
    }

    //Function for Right direction
    void rt() {
      digitalWrite(pin13, HIGH);
      digitalWrite(pin12, LOW);

      digitalWrite(pin7, LOW);
      digitalWrite(pin8, HIGH);
    }

    //Function for Stoping module
    void st() {
      digitalWrite(pin13, LOW);
      digitalWrite(pin12, LOW);

      digitalWrite(pin7, LOW);
      digitalWrite(pin8, LOW);
    }

    //Function for scanning distance fo both the directions
    void scan() {

      st();
      delay(500);

      myservo.write(180);
      Serial.println("left");
      distance_L = calculateDistance();
      Serial.println(distance_L);
      delay(500);


      myservo.write(90);
      delay(500);


      myservo.write(10);
      Serial.println("right");
      distance_R = calculateDistance();
      Serial.println(distance_R);
      delay(500);

      myservo.write(90);
      delay(500);
    }

void loop() {

  value = analogRead(potPin); //Read and save analog value from potentiometer
  value = map(value, 56, 1023, 0, 255); //Map value 0-1023 to 0-255 (PWM)
  Serial.println(value); 
  delay(100);                          //Small delay
  analogWrite(pinA5, value-7);
  analogWrite(pinA6, value);
  
  
  //calculating forward distance
  default_Distance = calculateDistance();
  Serial.println(default_Distance);

  //Checks whether there is not any obstacle for going forward
  if (default_Distance > 30) {
    fd();
  }

  //checks if any obstacle is detected
  else if (default_Distance < 30 && default_Distance > 0) {
    Serial.println("Scanning ....");
    scan();
    Serial.println("Scanning ....");

    //Checks if any side has space for escape
    if (distance_L > 30 || distance_R > 30) {

      if (distance_L > distance_R) {
        lt();
        delay(500);
        Serial.println("left turn derived");
        st();
        delay(1000);
      }

      else if (distance_R > distance_L) {
        rt();
        delay(500);
        Serial.println("right turn derived");
        st();
        delay(1000);
      }
    } else {
        analogWrite(pinA5, value-7);
        analogWrite(pinA6, value);
        rt();
        Serial.println("180 turn derived");
        delay(650);
    }
  }
}
