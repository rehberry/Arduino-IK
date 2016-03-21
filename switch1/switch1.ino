/*

  *** switch1 ***
 
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
  int a;

  if( Serial.available()) {
    a = Serial.parseInt();
  
   switch(a) {

      case 1: Serial.println("Das war eins ");

              break;

      case 2: Serial.println("Das war zwei "); 

              break;

      case 3: Serial.println("Das war drei ");

              break;

      case 4: Serial.println("Das war vier "); 

              break; 

      case 5: Serial.println("Das war fuenf ");

              break;

      }      /* Ende switch */
    
  }
}


