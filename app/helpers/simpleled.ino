// Program to blink an LED connected to pin D0
// of the Spark Core.

// We name pin D0 as led
int led = D0;

// This routine runs only once upon reset
void setup()
{
  Spark.function("ledrun", ledControl);
  // Initialize D0 pin as output
  pinMode(led, OUTPUT);
  digitalWrite(led, LOW);
}

// This routine loops forever
void loop()
{
  digitalWrite(led, HIGH);   // Turn ON the LED
}

int ledControl() {
  digitalWrite(led, HIGH);
  return 1;
}
