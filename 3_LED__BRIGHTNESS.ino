int readpin1 = 8;
int readpin2 = 9;
int readval1 = 8;
int readval2 = 9;
int cnt1;
int cnt2;
int cnt3;

int ledPin1 = 10;
int ledPin2 = 11;
int ledPin3 = 5;

void setup() {
  // put your setup code here, to run once:
  pinMode(readpin1, INPUT);
  pinMode(readpin2, INPUT);


  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  readval1 = digitalRead(readpin1);
  readval2 = digitalRead(readpin2);

  if (readval1 == 0 && readval2 == 1 && cnt1 < 255)
    cnt1++;
  else if (cnt1 > 0)
    cnt1--;

  if (readval1 == 1 && readval2 == 0 && cnt2 < 255)
    cnt2++;
  else if (cnt2 > 0)
    cnt2--;

  if (readval1 == 1 && readval2 == 1 && cnt3 < 255)
    cnt3++;
  else if (cnt3 > 0)
    cnt3--;


  Serial.println(cnt1);
  Serial.println(cnt2);
  Serial.println(cnt3);
  Serial.println();

  analogWrite(ledPin1, cnt1);
  analogWrite(ledPin2, cnt2);
  analogWrite(ledPin3, cnt3);


  delay(10);
}