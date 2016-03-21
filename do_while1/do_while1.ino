/*

  *** do_while1 ***
 
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
}


void loop() {
  int auswahl;

  Serial.println();
  Serial.println("-1- Auswahl1");
  Serial.println("-2- Auswahl2");
  Serial.println("-3- Auswahl3");
  Serial.println("-4- Programmende");
  Serial.println("Ihre Auswahl: ");
  Serial.println();
  
  do {
      if( Serial.available()) {
        auswahl = Serial.parseInt();

        switch(auswahl) {
          case 1  :  Serial.println("Das war Auswahl 1"); break;
          case 2  :  Serial.println("Das war Auswahl 2"); break;
          case 3  :  Serial.println("Das war Auswahl 3"); break;
          case 4  :  Serial.println("Programmende");      break;
          default :  Serial.println("Unbekannte Auswahl");
        }
      }  
   } while(auswahl!=4);
}


