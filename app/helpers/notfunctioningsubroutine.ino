int led = D0;

bool isComingHome;

int coming_home(String command)
{
  if (isComingHome) {
      isComingHome = false;
  } else {
      isComingHome = true;
  }
  return 0;
}

void setup()
{
  // Use serial port for debug print
  // Expose coming_home api
  Spark.function("coming_home", coming_home);

  pinMode(led, OUTPUT);
  digitalWrite(led, LOW);
}

void loop() {
  if (isComingHome) {
    digitalWrite(led, HIGH);
  } 
}