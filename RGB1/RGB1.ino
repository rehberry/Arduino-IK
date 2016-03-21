/*
 
 Sketch:        RGB1

 Author:        Wolfgang Reh
 
 Website:        http://www.rehlux.de
 
 Version:        V1.0
 
 Date:           16.01.2013
 
 Last modified:  16.01.2013
 
 Description:    Analog input, analog output, serial output

                Liest drei analogen Eingängen (R,G,B) ein, mapt sie auf einen Wert von
                0 bis 255 und stuert damit drei analoge Ausgänge (PWM) an. Zusätzlich wwerden
                die Werte der Ein- und Ausgänge über die serielle Schnittstelle ausgegeben.
                
                An den Ausgängen ist eine RGB-LED angeschlossen. Durch verändern der 
                Eingangswerte lassen sich verschiedene Farben einstellen.
                
                Die Schaltung:
                * An den drei analogen Eingängen A0. A1, A2 werden Potentiomter angeschlossen
                  A0 - Rot
                  A1 - Grün
                  A2 - Blau
                  
                * An den drei analogen Ausgängen 9, 10, 11 werden die ensprechenden Anschlüssen
                  der LED angeschlossen. Die verwendete LED LF5WAEMBGMBC von Kingbright hat eine
                  gemeinsame Kathode und zwei blaue LEDs, die aber zusammen betrieben werden können.
                  9  - Rot
                  10 - Grün
                  11 - Blau
                  Die Anschlüsse der LED sind dem Datenblatt zu entnehmen:
                  http://www.reichelt.de/index.html?;ACTION=7;LA=3;OPEN=0;INDEX=0;FILENAME=A500%252FLEDRGB-5%2523KIN.pdf
                  
*/


// Die verwendeten Pins werden mit einem Namen versehen

const int analogInPinR = A0;  // Analog input pin that the potentiometer is attached to
const int analogInPinG = A1;
const int analogInPinB = A2;
const int analogOutPinR = 9; // Analog output pin that the LED is attached to
const int analogOutPinG = 10;
const int analogOutPinB = 11;

int sensorValueR = 0;        // Werte am Eingan
int sensorValueG = 0;
int sensorValueB = 0;
int outputValueR = 0;        // Werte am Ausgang (PWM)
int outputValueG = 0;
int outputValueB = 0;

void setup() {
  // initialize serial communications at 9600 bps:
  Serial.begin(9600); 
}

void loop() {
  
  // Werte am Eingan einlesen:
  sensorValueR = analogRead(analogInPinR);
  sensorValueG = analogRead(analogInPinG);
  sensorValueB = analogRead(analogInPinB);
  
  // Auf den Wertebereich des Ausgangs anpassen:
  outputValueR = map(sensorValueR, 0, 1023, 0, 255);  // 10 Bit ADC am Eingang (0 - 1023)
  outputValueG = map(sensorValueG, 0, 1023, 0, 255);  // 8  Bit am PWM-Ausgang (0 - 255)
  outputValueB = map(sensorValueB, 0, 1023, 0, 255);

  // Ausgabe der eingestellten Werte:
  analogWrite(analogOutPinR, outputValueR);
  analogWrite(analogOutPinG, outputValueG);
  analogWrite(analogOutPinB, outputValueB);

  // Ausgabe der Werte über den  seriellen Monitor:
  Serial.print("Sensor ROT= " );                       
  Serial.print(sensorValueR);
  Serial.print("\t Sensor GRUEN= " );                       
  Serial.print(sensorValueG);
  Serial.print("\t Sensor BLAU= " );                       
  Serial.print(sensorValueB);
  
  Serial.print("\t Output ROT= ");      
  Serial.print(outputValueR);   
  Serial.print("\t Output GRUEN= ");      
  Serial.print(outputValueG);   
  Serial.print("\t Output BLAU= ");      
  Serial.println(outputValueB);   

  // wait 2 milliseconds before the next loop
  // for the analog-to-digital converter to settle
  // after the last reading:
  delay(2);                     
}
