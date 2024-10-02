//Techatronic.com

#include <Servo.h>
Servo servo1;
Servo servo2;

int angle = 0;
#define S1   3                 // Left arm
#define S2   4                // Right arm

#define ENA 7           // Enable/speed motors Right 
#define ENB 8          // Enable/speed motors Left  
#define led 5         // led EYE
#define buz 6        // buzzer

#define IN_1 9      // Motor driver inputs
#define IN_2 10          
#define IN_3 11           
#define IN_4 12 



void setup() 
{
  Serial.begin(9600);
pinMode(IN_1, OUTPUT);  
pinMode(IN_2, OUTPUT);
pinMode(IN_3, OUTPUT);
pinMode(IN_4, OUTPUT);
pinMode(ENA, OUTPUT);
pinMode(ENB, OUTPUT);
pinMode(led, OUTPUT);
pinMode(buz, OUTPUT);
 servo1.attach(S1);
 servo2.attach(S2);
 servo1.write(angle);
 servo2.write(angle);

}
void loop() 
{
  
 if (Serial.available()>0)
 {
  digitalWrite(led, LOW);
  char sig=char(Serial.read());
  Serial.println(sig);
  
  digitalWrite(led, HIGH);
 if (sig=='R')
{
  digitalWrite(led, LOW);
  servo1.write(60);
  servo2.write(0);
  digitalWrite(IN_1, HIGH);
  digitalWrite(IN_2, LOW);
  digitalWrite(IN_3, HIGH);
  digitalWrite(IN_4, LOW);
  digitalWrite(led, HIGH);
  servo1.write(0);
  servo2.write(60);
  }

  else if (sig=='L')
{
  digitalWrite(led, LOW);
  servo1.write(60);
  servo2.write(0);
digitalWrite(IN_1, LOW);
  digitalWrite(IN_2, HIGH);
  digitalWrite(IN_3, LOW);
  digitalWrite(IN_4, HIGH);
  digitalWrite(led, HIGH);
  servo1.write(0);
  servo2.write(60);
  }

else if (sig=='F')
{
  
  digitalWrite(led, LOW);
  servo1.write(60);
  servo2.write(0);
  digitalWrite(IN_1, HIGH);
  digitalWrite(IN_2, LOW);
  digitalWrite(IN_3, LOW);
  digitalWrite(IN_4, HIGH);
  digitalWrite(led, HIGH);
  servo1.write(0);
  servo2.write(60);
  
  }

 else if (sig=='B')
{
  
  digitalWrite(led, LOW);
  servo1.write(60);
  servo2.write(0);
  digitalWrite(IN_1, LOW);
  digitalWrite(IN_2, HIGH);
  digitalWrite(IN_3, HIGH);
  digitalWrite(IN_4, LOW);
  digitalWrite(led, HIGH);
  servo1.write(0);
  servo2.write(60);
  
  }


else if (sig=='W'){
 servo1.write(120);
 delay(150);
 servo2.write(0);
}
else if (sig=='w'){
 servo1.write(0);
 delay(150);
 servo2.write(0);
}
else if (sig=='U'){
 servo2.write(120);
 delay(150);
 servo1.write(0);
}
else if (sig=='u'){
 servo1.write(0);
 delay(150);
 servo2.write(0);
}
else if (sig=='V'){
 digitalWrite(buz, HIGH);
  Serial.print("Buzzer ON");

 delay(90);
 digitalWrite(buz, LOW);
 delay(90);
 digitalWrite(buz, HIGH);
}
else if (sig=='v'){
 digitalWrite(buz, LOW);
 Serial.print("Buzzer OFF");
}

else if(sig=='S')
{
  digitalWrite(led, LOW);
  servo1.write(60);
  servo2.write(0);
  digitalWrite(IN_1, LOW);
  digitalWrite(IN_2, LOW);
  digitalWrite(IN_3, LOW);
  digitalWrite(IN_4, LOW);
  delay(90);
  digitalWrite(led, HIGH);
  servo1.write(0);
  servo2.write(60);
  } 
}
}