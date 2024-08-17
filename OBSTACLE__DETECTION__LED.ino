
//Defining the pins
#define triggerpin 12
#define echopin 10
#define ledPin 9

//Declaring the variables
int duration = 0;
int distance = 0;
int val = 0;

void setup() {

  pinMode(triggerpin, OUTPUT);
  pinMode(echopin, INPUT);
  pinMode(ledPin, OUTPUT);

  Serial.begin(9600);

}

void loop() {

  //Generate Pulse
  digitalWrite(triggerpin, LOW);
  delayMicroseconds(2);

  digitalWrite(triggerpin, HIGH);
  delayMicroseconds(10);
  delay(100);

  digitalWrite(triggerpin,LOW);

  //Calculate Diastance
  duration = pulseIn(echopin, HIGH);
  distance = (duration * 0.0343) / 2;
  Serial.println(distance);

  
  if (distance < 50)
    val = map(distance, 2, 50, 255, 0);
  else
    val = 0;

   Serial.println(val);

  analogWrite(ledPin, val);
  delay(100);  
}