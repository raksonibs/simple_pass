Servo myservo;  // create servo object to control a servo 
                // a maximum of eight servo objects can be created 

int pos = 0; // variable to store the servo position 
bool runFlag = true;

void setup() 
{ 
  myservo.attach(D0);  // attaches the servo on pin 0 to the servo object 
  resetPosition();
} 

void resetPosition()
{
  int pos = myservo.read();
  for (int i = pos; i > 3; i--) {
    myservo.write(i);
    delay(50);
  }
}

void loop() 
{ 
  if (runFlag) {
    for (int i = 0; i < 50; i++) {
      delay(50);
      myservo.write(i * (90.0 / 50.0));
    }
    runFlag = false;
    resetPosition();
    myservo.detach();
  }
   
}