// Controlling LEDs over the Internet
// -----------------------------------

// no need for playing cards,
// figured out will have flag which will indiciate what order of buttons she has to click. Once that is done, it will 
// give her the code via the iphone app label? she clicks the buttons via the iphone app, with one start telling her which
// to click! No need for cards, because that is a little bit annoying
// note that will not have off sequence, will just turn lights off after some delay in seconds and reset everything
// need to actuall set this up now with iphone and the servo code.
// servo will have flag for order while ihpone will have four buttons, start for servo and each corresponding light
// failure will go off as registered here
// need to make sure cannot click somehow when failure going off
// would be nice to have transitions of some sort, but make rectangular start with three small circles for each button
// and when success servo can rotate the flag to a happy face with the yellow flashing light and give her the code for the last lock on the iphone
bool onefirst = false;
bool twosecond = false;
bool thirdthird = false;

// name the pins
int led1 = D0;
int led2 = D1;
int led3 = D2;
int success = D3;
int failure = D4;
// This routine runs only once upon reset
void setup()
{
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

// code is 1,2,3
// This routine loops forever
void loop()
{
   // Nothing to do here
   if (onefirst) {
       if (twosecond) {
           if (thirdthird) {
               Serial.println("Should turn success on!");
               digitalWrite(success, HIGH);
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
   Serial.println(onefirst);
   if (pinNumber == 0 && onefirst == 0) {
       onefirst = true;
       Serial.println("entering to change one");
   }
   Serial.println("first one after l1 goes on");
   Serial.println(onefirst);
   Serial.println("second one before click");
   Serial.println(twosecond);
//   might not work because onefirst always set to false?
   if (pinNumber == 1 && twosecond == false) {
       Serial.println("second one hopefully changing");
       twosecond = true;
   }
   Serial.println("second one after loop");
   Serial.println(twosecond);
   
   Serial.println("third one before click");
   Serial.println(thirdthird);
//   might not work because onefirst always set to false?
   if (pinNumber == 2 && thirdthird == false) {
       Serial.println("third one hopefully changing");
       thirdthird = true;
   }
   Serial.println("third one after loop");
   Serial.println(thirdthird);
//   if click second button and first one is false, reset all values, and print error (will be error light) 
   if (pinNumber == 1 && onefirst == false) {
       Serial.println("Error: Redo because clicked two and one not done");
       twosecond = false;
       onefirst = false;
       thirdthird = false;
       digitalWrite(0, 0);
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
   
   if (pinNumber == 2 && (onefirst == false || twosecond == false)) {
       Serial.println("Error: Redo because clicked three and one or two not done");
       twosecond = false;
       onefirst = false;
       thirdthird = false;
       digitalWrite(0, 0);
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

   // find out the state of the led
   if(command.substring(3,7) == "HIGH") state = 1;
   else if(command.substring(3,6) == "LOW") state = 0;
   else return -1;

   // write to the appropriate pin
   digitalWrite(pinNumber, state);
    // right now just righting to a third digitial output to see if works
   return 1;
}