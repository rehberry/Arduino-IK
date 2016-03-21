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

float cal = 0.49;              
int activePin = 12;
int gut_LED = 8;
int schlecht_LED = 9;
float Sollwert = 100000.0;
float Toleranz = 10.0;
float chargingTime = 0.0;
float capacity = 0.0;


void setup() {
  pinMode(gut_LED,OUTPUT);  
  pinMode(schlecht_LED,OUTPUT);  
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
  
  Toleranz_Anzeige(capacity,Sollwert,Toleranz,gut_LED,schlecht_LED);

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

void Toleranz_Anzeige(float Messwert, float Sollwert, float Toleranz, int gut_LED, int schlecht_LED) {
  float x;
  x = Messwert - Sollwert;
  x = abs(x);
  
  Toleranz = Sollwert * Toleranz / 100;
  
  if (x <= Toleranz) {
    digitalWrite(schlecht_LED,LOW);
    digitalWrite(gut_LED,HIGH);
  }
  
  else {
    digitalWrite(gut_LED,LOW);
    digitalWrite(schlecht_LED,HIGH);
  }
}


