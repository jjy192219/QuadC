#include <Firmata.h>  

int bHitPin = 6;
int distancePin = 7;
int trigPin = 8;
int echoPin = 9;

void setup() {
  Firmata.begin(9600);

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
  Serial.println(hitRes);
  return hitRes;
}

long getDis(){  
  long duration, distance;
  pinMode(trigPin, OUTPUT);
  digitalWrite(trigPin, LOW);  
  delayMicroseconds(2); // Added this line
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10); // Added this line
  digitalWrite(trigPin, LOW);
  pinMode(echoPin, INPUT);
  duration = pulseIn(echoPin, HIGH);
  distance = duration /29/2;

  if(distance <= 200 && distance >0){
    Serial.print(distance);
    Serial.println(" cm");
    return distance;
  }else{
    Serial.println("out of range");  
  }

}  


