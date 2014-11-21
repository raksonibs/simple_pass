int led = D7;
bool isOn = false;

void setup() {
  Serial.begin(9600);
  pinMode(A0, INPUT);
  pinMode(led, OUTPUT);
  digitalWrite(led, LOW);
}

void loop() {
  int voltage = analogRead(A0);
  bool isDark = voltage <= 150;
  if (isDark && isOn) {

  } else if (isDark && !isOn) {
    digitalWrite(led, HIGH);
    isOn = true;
  } else {
    digitalWrite(led, LOW);
    isOn = false;
  }
  delay(500);
}

//  ls -la /dev/tty.usb*
//screen /dev/tty.usbmodem1411  9600 