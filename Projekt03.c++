const int sensorPin = A0;
const float baselineTemp = 20.0;

void setup() {
  Serial.begin(9600);

  for (int pinNumber = 2; pinNumber < 9; pinNumber++) { // 2–8
    pinMode(pinNumber, OUTPUT);
    digitalWrite(pinNumber, LOW);
  }
}

void loop() {
  int sensorVal = analogRead(sensorPin);

  float voltage = (sensorVal / 1023.0) * 5.0; // täpsem
  float temperature = (voltage - 0.5) * 100;

  Serial.print("Temp: ");
  Serial.println(temperature);

  // Kustuta kõik LED-id
  for (int pin = 2; pin < 9; pin++) {
    digitalWrite(pin, LOW);
  }

  // Temperatuuritase 5–8 LED-iga
  if (temperature < baselineTemp) {
    digitalWrite(2, HIGH);
  }
  else if (temperature < baselineTemp + 3) {
    digitalWrite(2, HIGH);
    digitalWrite(3, HIGH);
  }
  else if (temperature < baselineTemp + 6) {
    digitalWrite(2, HIGH);
    digitalWrite(3, HIGH);
    digitalWrite(4, HIGH);
  }
  else if (temperature < baselineTemp + 9) {
    digitalWrite(2, HIGH);
    digitalWrite(3, HIGH);
    digitalWrite(4, HIGH);
    digitalWrite(5, HIGH);
  }
  else if (temperature < baselineTemp + 12) {
    digitalWrite(2, HIGH);
    digitalWrite(3, HIGH);
    digitalWrite(4, HIGH);
    digitalWrite(5, HIGH);
    digitalWrite(6, HIGH);
  }
  else if (temperature < baselineTemp + 15) {
    digitalWrite(2, HIGH);
    digitalWrite(3, HIGH);
    digitalWrite(4, HIGH);
    digitalWrite(5, HIGH);
    digitalWrite(6, HIGH);
    digitalWrite(7, HIGH);
  }
  else {  // kõik ülejäänud juhtumid
    digitalWrite(2, HIGH);
    digitalWrite(3, HIGH);
    digitalWrite(4, HIGH);
    digitalWrite(5, HIGH);
    digitalWrite(6, HIGH);
    digitalWrite(7, HIGH);
    digitalWrite(8, HIGH);
  }

  delay(500);
}