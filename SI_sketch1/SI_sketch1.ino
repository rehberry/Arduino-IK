/*

  *** Blink ***
 
 Author:         Wolfgang Reh 
 
 Website:        http://moodle1.wreh.eu
 
 Version:        1.0
 
 Date:           16.08.2012
 
 Last modified:  
 
 Description:    Turns on an LED on for one second, then off for one second, repeatedly.
 
 Referenz:       http://moodle1.wreh.eu/course/view.php?id=129
 
 */

// Pin 13 has an LED connected on most Arduino boards.
// give it a name:
#define led 13

// the setup routine runs once when you press reset:

void setup() {
  // initialize the digital pin as an output.
  pinMode(led, OUTPUT);
}


void loop() {
  digitalWrite(led, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000);               // wait for a second
  digitalWrite(led, LOW);    // turn the LED off by making the voltage LOW
  delay(1000);               // wait for a second
}


