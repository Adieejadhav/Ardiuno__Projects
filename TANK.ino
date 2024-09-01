//defining the pins for two DC motors 
//two analog pins for controlling speed of the DC motors
//one pin for controlling the shooting the of gun
#define pin13 13
#define pin12 12
#define pin8 8
#define pin7 7
#define pin9 9
#define pinA5 5
#define pinA6 6

void setup() {
  // put your setup code here, to run once:

//all the pins we are using are OUTPUT that's why
//we are setting them as OUTPUT 
  pinMode(pin13, OUTPUT);
  pinMode(pin12, OUTPUT);
  pinMode(pin8, OUTPUT);
  pinMode(pin7, OUTPUT);
  pinMode(pin9, OUTPUT);


//Analog pins are also used for the OUTPUT
  pinMode(pinA5, OUTPUT);
  pinMode(pinA6, OUTPUT);

//initializing the serial monitor
  Serial.begin(9600);
}

//Created the function for FORWARD movement of tank
void fd() {
  digitalWrite(pin13, HIGH);
  digitalWrite(pin12, LOW);

  digitalWrite(pin7, HIGH);
  digitalWrite(pin8, LOW);
}

//Created the function for BCKWARD movement of tank
void bd() {
  digitalWrite(pin13, LOW);
  digitalWrite(pin12, HIGH);

  digitalWrite(pin7, LOW);
  digitalWrite(pin8, HIGH);
}

//Created the function for LEFT movement of tank
void lt() {
  digitalWrite(pin13, LOW);
  digitalWrite(pin12, HIGH);

  digitalWrite(pin7, HIGH);
  digitalWrite(pin8, LOW);
}

//Created the function for RIGHT movement of tank
void rt() {
  digitalWrite(pin13, HIGH);
  digitalWrite(pin12, LOW);

  digitalWrite(pin7, LOW);
  digitalWrite(pin8, HIGH);
}

//Created the function for STOPPING the tank
void st() {
  digitalWrite(pin13, LOW);
  digitalWrite(pin12, LOW);

  digitalWrite(pin7, LOW);
  digitalWrite(pin8, LOW);

  digitalWrite(pin9, HIGH);
}

//Created the function for SHOOTING from the gun
void shoot(){
  digitalWrite(pin9, LOW);
  
}

void loop() {
  // put your main code here, to run repeatedly:
  
//setting the full spedd fo the DC motors
  analogWrite(pinA5, 255);
  analogWrite(pinA6, 255);

  char incomingByte = 'Z';

//communication of the blutooth will occurs through the serial monitor 
//that's why we'll cheack if any value is present or not at serial monitor 
//if any value is coming then we'll cheack what is present
  if (Serial.available() > 0) {
    incomingByte = Serial.read();
    Serial.println(incomingByte);
  }

//if incoming value is 'F' then tank will move forward
  if (incomingByte == 'F') {
    fd();
  }

//if incoming value is 'B' then tank will move backward  
  if (incomingByte == 'B') {
    bd();
  }

//if incoming value is 'L' then tank will move left
  if (incomingByte == 'L') {
    lt();
  }

//if incoming value is 'R' then tank will move right  
  if (incomingByte == 'R') {
    rt();
  }

//if incoming value is 'S' then tank will stop 
  if (incomingByte == 'S') {
    st();
  }

//if incoming value is 'A' then we will fire
  if (incomingByte == 'A') {
    shoot();
  }  
}