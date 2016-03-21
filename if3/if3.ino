/*

  *** if1 ***
 
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
  unsigned int alter;

  if( Serial.available()) {
    alter = Serial.parseInt();
  
    if(alter < 18) {

      Serial.println("Sie sind noch nicht volljaehrig");

    }

    else if(alter > 18)  {

      Serial.println("Sie sind volljaehrig");

    }

    else if(alter == 18) {

      Serial.println("Den Fuehrerschein schon bestanden?");

    }

    Serial.println("Bye");
    
  }
}


