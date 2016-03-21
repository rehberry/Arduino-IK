/*

  *** while2 ***
 
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
  int zahl, summe=0;
  Serial.println("Summenberechnung (Beenden der Eingabe mit 0)");
  
  while(1) {          /* Endlosschleife, denn: 1 ist immer wahr */
    if( Serial.available()) {
      zahl = Serial.parseInt();
      if(zahl == 0)      /* Haben wir 0 eingegeben ...? */
        break;             /* ... dann raus aus der Schleife */
      else
        summe+=zahl;
    }
  }
  Serial.print("Die Summe aller Werte betraegt: ");
  Serial.println(summe);  
}


