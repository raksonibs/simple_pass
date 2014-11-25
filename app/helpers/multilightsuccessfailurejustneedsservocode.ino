// Controlling LEDs over the Internet
// -----------------------------------

// no need for playing cards,
// figured out will have flag which will indiciate what order of buttons she has to click. Once that is done, it will 
// give her the code via the iphone app label? she clicks the buttons via the iphone app, with one start telling her which
// to click! No need for cards, because that is a little bit annoying
// note that will not have off sequence, will just turn lights off after some delay in seconds and reset everything
// changed to second first third

Servo myservo;  // create servo object to control a servo 
                // a maximum of eight servo objects can be created 

int pos = 0; // variable to store the servo position 
bool runFlag = true;

bool first = false;
bool second = false;
bool third = false;

// name the pins
int led1 = D5;
int led2 = D1;
int led3 = D2;
int success = D3;
int failure = D4;

// This routine runs only once upon reset
void setup()
{ 
   myservo.attach(D0);
   resetPosition();
     Serial.begin(9600);
   //Register our Spark function here
   Spark.function("led", ledControl);

   // Configure the pins to be outputs
   pinMode(led1, OUTPUT);
   pinMode(led2, OUTPUT);
   pinMode(led3, OUTPUT);
   pinMode(success, OUTPUT);
   pinMode(failure, OUTPUT);

   // Initialize both the LEDs to be OFF
   digitalWrite(led1, LOW);
   digitalWrite(led2, LOW);
   digitalWrite(led3, LOW);
   digitalWrite(success, LOW);
   digitalWrite(failure, LOW);
}

void resetPosition()
{
  int pos = myservo.read();
  for (int i = pos; i > 3; i--) {
    myservo.write(i);
    delay(50);
  }
}

// code is 1,2,3
// This routine loops forever
void loop()
{
   // Nothing to do here
   if (first) {
       if (second) {
           if (third) {
               Serial.println("Should turn success on!");
               digitalWrite(success, HIGH);
               // put servo on
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
        //   want to send value to change label on iphone basically
       }
   } else {
       digitalWrite(led1, LOW);
       digitalWrite(led2, LOW);
       digitalWrite(led3, LOW);
   }
}


// This function gets called whenever there is a matching API request
// the command string format is l<led number>,<state>
// for example: l1,HIGH or l1,LOW
//              l2,HIGH or l2,LOW
// will need to reset lights if they are not working or incorrect code
// second first third
int ledControl(String command)
{
   int state = 0;
   //find out the pin number and convert the ascii to integer
   int pinNumber = (command.charAt(1) - '0') - 1;
   //Sanity check to see if the pin numbers are within limits
   if (pinNumber < 0 || pinNumber > 3) return -1;
   Serial.println("pin number");
   Serial.println(pinNumber);
   Serial.println("first one before l1");
   Serial.println(first);
//   first button is second key
   if (pinNumber == 0 && second == 0) {
       second = true;
       Serial.println("entering to change one");
   }
   Serial.println("first one after l1 goes on");
   Serial.println(second);
   Serial.println("second one before click");
   Serial.println(first);
//   might not work because onefirst always set to false?
   if (pinNumber == 1 && first == false) {
       Serial.println("second one hopefully changing");
       first = true;
   }
   Serial.println("second one after loop");
   Serial.println(first);
   
   Serial.println("third one before click");
   Serial.println(third);
//   might not work because onefirst always set to false?
   if (pinNumber == 2 && third == false) {
       Serial.println("third one hopefully changing");
       third = true;
   }
   Serial.println("third one after loop");
   Serial.println(third);
//   if click second button and first one is false, reset all values, and print error (will be error light) 
   if (pinNumber == 0 && first == false) {
       Serial.println("Error: Redo because clicked two and one not done");
       second = false;
       first = false;
       third = false;
       digitalWrite(5, 0);
       digitalWrite(1, 0);
       digitalWrite(2, 0);
       digitalWrite(4, HIGH);
       delay(1000);
       digitalWrite(4, LOW);
       delay(1000);
       digitalWrite(4, HIGH);
       delay(1000);
       digitalWrite(4, LOW);
       delay(1000);
       digitalWrite(4, HIGH);
       delay(1000);
       digitalWrite(4, LOW);
       delay(1000);
    //   digitalWrite(3, 1); whatever errror is
   }
   
   if (pinNumber == 2 && (first == false || second == false)) {
       Serial.println("Error: Redo because clicked three and one or two not done");
       second = false;
       first = false;
       third = false;
       digitalWrite(5, 0);
       digitalWrite(1, 0);
       digitalWrite(2, 0);
       digitalWrite(4, HIGH);
       delay(1000);
       digitalWrite(4, LOW);
       delay(1000);
       digitalWrite(4, HIGH);
       delay(1000);
       digitalWrite(4, LOW);
       delay(1000);
       digitalWrite(4, HIGH);
       delay(1000);
       digitalWrite(4, LOW);
       delay(1000);
    //   digitalWrite(3, 1); whatever errror is
   }
//   if (twosecond && onefirst) {
//       digitalWrite(D3, HIGH);
//   }

    if (pinNumber == 0) {
        pinNumber = 5;
    }

   // find out the state of the led
   if(command.substring(3,7) == "HIGH") state = 1;
   else if(command.substring(3,6) == "LOW") state = 0;
   else return -1;

   // write to the appropriate pin
   digitalWrite(pinNumber, state);
    // right now just righting to a third digitial output to see if works
   return 1;
}