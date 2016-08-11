#include <Firmata.h>  

int bHitPin = 6;
int distancePin = 7;
int trigPin = 8;
int echoPin = 9;

void setup() {
  Firmata.begin(57600);

}

void loop() {
   while(Firmata.available()) {  
      Firmata.processInput();  
   }
   Firmata.sendAnalog(bHitPin, getHit());
   Firmata.sendAnalog(distancePin, getDis());
}

int getHit(){
  int hitRes;
  hitRes = analogRead(A0);
//  hitRes = map(analogRead(A0), 0, 1023, 0, 255);
  Serial.println(hitRes);
  return hitRes;
}

long getDis(){  
  long duration, distance;
  digitalWrite(trigPin, LOW);  // Added this line
  delayMicroseconds(2); // Added this line
  digitalWrite(trigPin, HIGH);
//  delayMicroseconds(1000); - Removed this line
  delayMicroseconds(10); // Added this line
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration/2) / 29.1;
 
  if (distance >= 200 || distance <= 0){
    Serial.println("Out of range");
  }
  else {
    Serial.print(distance);
    Serial.println(" cm");
  }

  return distance;
}  


