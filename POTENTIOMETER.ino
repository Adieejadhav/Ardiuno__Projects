const int ledPin = 9;  //pin 9 has PWM funtion
const int potPin = A0; //pin A0 to read analog input

//Variables:
  int value; //save analog value


void setup(){
  //Input or output?
  pinMode(ledPin, OUTPUT); 
  pinMode(potPin, INPUT);
  Serial.begin(9600);
}

void loop(){

  //Read and save analog value from potentiometer
  value = analogRead(potPin);

   //Map value 0-1023 to 0-255 (PWM) 
  value = map(value, 56, 1023, 0, 255);
  Serial.println(value);

  //Send PWM value to led
  analogWrite(ledPin, value); 

  //Small delay
  delay(100);                          
  
}

