int switchState = 0;

void setup() {
  pinMode(3, OUTPUT); // punane
  pinMode(4, OUTPUT); // punane
  pinMode(5, OUTPUT); // roheline
  pinMode(2, INPUT);  // nupp
}

void loop() {
  switchState = digitalRead(2);

  if (switchState == LOW) {
    // nupp EI ole vajutatud → punased vilguvad
    digitalWrite(5, LOW); // roheline OFF

    digitalWrite(3, HIGH);
    digitalWrite(4, LOW);
    delay(250);

    digitalWrite(3, LOW);
    digitalWrite(4, HIGH);
    delay(250);
  } 
  else {
    // nupp ON vajutatud → roheline põleb
    digitalWrite(3, LOW); // punased OFF
    digitalWrite(4, LOW);
    digitalWrite(5, HIGH); // roheline ON
  }
}