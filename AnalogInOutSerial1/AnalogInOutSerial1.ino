/*
  Analog input, analog output, serial output
 
 Reads an analog input pin, maps the result to a range from 0 to 255
 and uses the result to set the pulsewidth modulation (PWM) of an output pin.
 Also prints the results to the serial monitor.
 
 The circuit:
 * potentiometer connected to analog pin 0.
   Center pin of the potentiometer goes to the analog pin.
   side pins of the potentiometer go to +5V and ground
 * LED connected from digital pin 9 to ground
 
 created 29 Dec. 2008
 modified 9 Apr 2012
 by Tom Igoe
 
 This example code is in the public domain.
 
 */

// These constants won't change.  They're used to give names
// to the pins used:
const int analogInPin0 = A0;  // Analog input pin that the potentiometer is attached to
const int analogInPin1 = A1;
const int analogInPin2 = A2;
const int analogOutPin0 = 9; // Analog output pin that the LED is attached to
const int analogOutPin1 = 10;
const int analogOutPin2 = 11;

int sensorValue0 = 0;        // value read from the pot
int sensorValue1 = 0;
int sensorValue2 = 0;
int outputValue0 = 0;        // value output to the PWM (analog out)
int outputValue1 = 0;
int outputValue2 = 0;

void setup() {
  // initialize serial communications at 9600 bps:
  Serial.begin(9600); 
}

void loop() {
  // read the analog in value:
  sensorValue0 = analogRead(analogInPin0);
  sensorValue1 = analogRead(analogInPin1);
  sensorValue2 = analogRead(analogInPin2);
  // map it to the range of the analog out:
  outputValue0 = map(sensorValue0, 0, 1023, 0, 255);
  outputValue1 = map(sensorValue1, 0, 1023, 0, 255);
  outputValue2 = map(sensorValue2, 0, 1023, 0, 255);
  // change the analog out value:
  analogWrite(analogOutPin0, outputValue0);
  analogWrite(analogOutPin1, outputValue1);
  analogWrite(analogOutPin2, outputValue2);

  // print the results to the serial monitor:
//  Serial.print("sensor = " );                       
//  Serial.print(sensorValue);      
//  Serial.print("\t output = ");      
//  Serial.println(outputValue);   

  // wait 2 milliseconds before the next loop
  // for the analog-to-digital converter to settle
  // after the last reading:
  delay(2);                     
}
