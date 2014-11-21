void setup() {
  Serial.begin(9600); // open serial over USB
  pinMode(A0, INPUT);
}

void loop() {
  Serial.println(analogRead(A0));
  delay(500);
}