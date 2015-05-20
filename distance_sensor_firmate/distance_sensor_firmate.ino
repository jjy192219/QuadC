#include <Firmata.h>  

byte digitalPin;  
char firstChar;   
char secondChar;  
int distanceResultPin = 7;  
int flexResultPin = 8;  

int flexPin = A0;  


int trigPin = 13;
int echoPin = 12;


void setup()  
{  

    Firmata.begin();  
}  

void loop()  
{  
   while(Firmata.available()) {  
      Firmata.processInput();  
   }  

   Firmata.sendAnalog(distanceResultPin, computeDistance()); 
   Firmata.sendAnalog(flexResultPin, computeFlex());  
 
}  

long computeDistance(){  
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
    return distance;
  }
  delay(500);
}  

int computeFlex(){
  int flexposition;
  flexposition = analogRead(flexPin);
  Serial.print("flex: ");
  Serial.println(flexposition);
  return flexposition; 
  
}
