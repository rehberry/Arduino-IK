/*
 
 Author:        Wolfgang Reh
 
 Website:        http://www.rehlux.de
 
 Version:        V1.0
 
 Date:           16.01.2013
 
 Last modified:  16.01.2013
 
 Description:    Durch die Bestimmung der Ladezeit wird die Kapazität 
                 eines Kondensators gemessen und über die serielle 
                 Schnittstelle ausgegeben.
 
 Referenz:
 
 */

float cal = 0.5;              
int activePin = 12;
float chargingTime = 0.0;
float capacity = 0.0;


void setup() {
  Serial.begin(9600);
}


void loop() {
  pinMode(activePin,OUTPUT);
  digitalWrite(activePin,LOW);
  chargingTime=0.0;
  delay(10000);

  pinMode(activePin,INPUT);
  digitalWrite(activePin,HIGH);

  while(!digitalRead(activePin)){
    chargingTime++;
  }

  capacity=chargingTime*cal;                       

  if(capacity < 1000){
    Serial.print(capacity);
    Serial.println(" nF        ");
  }

  else{
    capacity = capacity/1000;
    Serial.print(capacity);
    Serial.println(" uF        ");

  }

  delay(1000);
}


