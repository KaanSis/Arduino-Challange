#define trigPin 13
#define echoPin 12
int counter = 0;
int currentState = 0;
int previousState = 0;
void setup() {
 Serial.begin (9600);
 pinMode(trigPin, OUTPUT);
 pinMode(echoPin, INPUT);
}

void loop() {
 long duration, distance;
 digitalWrite(trigPin, LOW); 
 delayMicroseconds(2); 
 digitalWrite(trigPin, HIGH);
 delayMicroseconds(10); 
 digitalWrite(trigPin, LOW);
 duration = pulseIn(echoPin, HIGH);
 distance = (duration/2) / 29.1;

 if (distance <= 250){ 
 currentState = 1;
 }
 else {
 currentState = 0;
 }
 delay(500);
 if(currentState != previousState){
if(currentState == 1){
counter = counter + 1;
Serial.println(counter);
    }
  }
}
