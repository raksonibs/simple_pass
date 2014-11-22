int led = D0;

#define PRINTF_BUFFER_SIZE 128
void Serial_printf(const char* fmt, ...) {
   char buff[PRINTF_BUFFER_SIZE];
   va_list args;
   va_start(args, fmt);
   vsnprintf(buff, PRINTF_BUFFER_SIZE, fmt, args);
   va_end(args);
   Serial.println(buff);
}

bool isComingHome = false;

int coming_home(String command)
{
  isComingHome = true;
  return 0;
}

void setup()
{
  // Use serial port for debug print
  Serial.begin(9600);

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