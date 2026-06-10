int sensorValue;
int sensorLow = 1023;
int sensorHigh = 0; 
const int LedPin = 13;
void setup() {
  pinMode(LedPin, OUTPUT);
  digitalWrite(LedPin, HIGH);
  while(millis() < 5000) {
    sensorValue = analogRead (A0);
    if (sensorValue > sensorHigh){
      sensorHigh = sensorValue;
    }
    if (sensorValue < sensorLow){
      sensorLow = sensorValue;
    }
  }
  digitalWrite(LedPin, LOW);
}
void loop() {
sensorValue = analogRead(A0);
int pitch =
map(sensorValue,sensorLow,sensorHigh, 50, 4000);

tone(8,pitch,20);

delay(10);
}