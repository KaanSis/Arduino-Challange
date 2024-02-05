#include <Servo.h>
Servo servo1;
Servo servo2;
int location1=90;  
int location2=90; 


int sensorSVJ1;
int sensorSVJ2;
int sensorSVJ3;
int sensorSVJ4;

void setup() {   
  Serial.begin(9600); 
  servo1.attach(8);
  servo2.attach(9);
  servo1.write(location1);  
  servo2.write(location2);  
}

void loop() {   
 
  sensorSVJ1 = analogRead(A0); 
  sensorSVJ2 = analogRead(A1); 
  sensorSVJ3 = analogRead(A2); 
  sensorSVJ4 = analogRead(A3); 
  
  if (sensorSVJ1+20<sensorSVJ2) 
      {
        location1=location1-1;
        if (location1<0) 
            {
              location1=0;
            }
      }
     if (sensorSVJ1>sensorSVJ2+20)
      {
        location1=location1+1;
        if (location1>180)
            {
              location1=180;
            } 
      }
  
   if (sensorSVJ3+20<sensorSVJ4) 
      {
        location2=location2-1;
        if (location2<0)
            {
              location2=0;
            }          
      }
     if (sensorSVJ3>sensorSVJ4+20)
      {
        location2=location2+1;
        if (location2>180)
            {
              location2=180;
            } 
      }
  
  Serial.print("  left ");
  Serial.print(sensorSVJ1);
  Serial.print("  right ");
  Serial.print(sensorSVJ2);
  Serial.print("  location1 ");
  Serial.print(location1);
  Serial.print(" up ");
  Serial.print(sensorSVJ3);
  Serial.print(" down  ");
  Serial.print(sensorSVJ4);
  Serial.print("  location2 ");
  Serial.println(location2); 

delay(100);

servo1.write(location1); 
servo2.write(location2);    

} 
