//This program is for the increasing the brightness of the led on pressing the  switch
//and decreasing it when switch is released


//defining one readpin for reading the values from switch
//and one for led pin
#define readPin 13
#define ledAnalogPin 9

//declaring the counter for increasing and decreasing the brightness
//and readval for saving the value from switch 
int cnt;
int readVal;

void setup() {

//setting them for OUTPUT
  pinMode(readPin, INPUT);
  pinMode(ledAnalogPin, OUTPUT);
  Serial.begin(9600);

}


void loop() {
//reading and saving the values from switch into the readval
  readVal = digitalRead(readPin);

//controls the brightness of led according to the ssawitch movement
  if (readVal == 1 && cnt < 255) {
    cnt++;
  } else if (readVal == 0 && cnt > 0) {
    cnt--;
  }

  Serial.println(cnt);

//writting the counter variable into led's brightness
  analogWrite(ledAnalogPin, cnt);
  
  delay(10);
}

