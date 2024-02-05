#include <Servo.h>
Servo servo;

void setup()
{
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(A1, INPUT);
  servo.attach(7);
  Serial.begin(9600);  
}

const int SIZE = 4;
int password[SIZE] = {0, 2, 1, 3};
int num;

void loop()
{
  for (int i = 0; i < SIZE; i++)
  {
	servo.write(0);
	num = map(analogRead(A1), 0, 1023, 0, 7);
  	Serial.println(num);
    
 	if (num == password[i])
	{
      	if (i == 1) digitalWrite(2, HIGH);
        if (i == 2) digitalWrite(3, HIGH);
        if (i == 3) digitalWrite(4, HIGH);
  		if (i == 0) 
  		{
            digitalWrite(5, HIGH);
    		servo.write(90);
    		Serial.println("This case is opened");
    		delay(5000);
    		Serial.println("This case is closed");
          
          digitalWrite(2, LOW);
          digitalWrite(3, LOW);
          digitalWrite(4, LOW);
          digitalWrite(5, LOW);
          servo.write(0);

  		}
    Serial.print("Code ");
    Serial.println(i);
	}
  
	else
	{
		i = 0;  
  		Serial.println("The password is wrong");
        digitalWrite(2, LOW);
        digitalWrite(3, LOW);
        digitalWrite(4, LOW);
        digitalWrite(5, LOW);
	}
  	delay(2000);
  }
}
