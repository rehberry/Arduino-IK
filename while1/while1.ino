/*

  *** while1 ***
 
 Author:         Wolfgang Reh 
 
 Website:        http://moodle1.wreh.eu
 
 Version:        1.0
 
 Date:           03.03.2015
 
 Last modified:  
 
 Description:    Beispiel einer if-Verzweigung
 Referenz:       http://arduino.cc/en/Reference/HomePage
 
 */


void setup() {
    Serial.begin(9600); // opens serial port, sets data rate to 9600 bps

  int zahl=1, tmp=0;

  while(zahl <= 10) {
    tmp=tmp+zahl;
    Serial.print("+");
    Serial.print(zahl++);     /* Zahl + 1 */
  } 
  Serial.print(" =");
  Serial.println(tmp);
} 


void loop() {
}


