/* BLUETOOTH CAR WITH ARDUINO UNO AND HC-05

   THIS CODE DEMONSTRATES CONTROLLING A CAR VIA SMARTPHONE USING BLUETOOTH COMMUNICATION.

   NOTE-IT IS ADVISED THAT BLUETOOTH MODULE SHOULD BE ATTACHED TO ARDUINO BOARD AFTER
        UPLOADING CODE TO AVOID ERRORS AND PREVENT POSSIBLE DAMAGE TO BLUETOOTH MODULE.

   CODE CREATED BY - AMEYA ANGADI
   LAST MODIFIED ON - 10/03/2022
   VERSION - 1.2
*/

//#define led1 = 13
#define in1 = 12
#define in2 = 11
#define in3 = 10
#define in4 = 9
#define led = 5         // led EYE
#define buz = 6        // buzzer
#include <Servo.h>
Servo servo1;
Servo servo2;

void setup() {
  
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(13, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
servo1.attach(3);
 servo2.attach(4);
 servo1.write(0);
 servo2.write(0);
 Serial.begin(9600);
}

void loop() {
  if (Serial.available() > 0) {
    char inputvalue = char(Serial.read());
    if (inputvalue == 'F') {
      digitalWrite(5, HIGH);
      servo1.write(60);
      servo2.write(0);
      digitalWrite(12, HIGH);
      digitalWrite(11, LOW);
      digitalWrite(10, HIGH);
      digitalWrite(9, LOW);
     digitalWrite(5, LOW);
      servo1.write(0);
      servo2.write(60);
    }
    else if (inputvalue == 'B') {
      digitalWrite(5, HIGH);
      servo1.write(60);
      servo2.write(0);
      digitalWrite(12, LOW);
      digitalWrite(11, HIGH);
      digitalWrite(10, LOW);
      digitalWrite(9, HIGH);
      digitalWrite(5, LOW);
      servo1.write(0);
      servo2.write(60);
    }

    else if (inputvalue == 'R') {
      digitalWrite(5, HIGH);
      servo1.write(60);
      servo2.write(0);
      digitalWrite(12, LOW);
      digitalWrite(11, LOW);
      digitalWrite(10, HIGH);
      digitalWrite(9, LOW);
      digitalWrite(5, LOW);
      servo1.write(0);
      servo2.write(60);
    }

    else if (inputvalue == 'L') {
      digitalWrite(5, HIGH);
      servo1.write(60);
      servo2.write(0);
      digitalWrite(12, HIGH);
      digitalWrite(11, LOW);
      digitalWrite(10, LOW);
      digitalWrite(9, LOW);
      digitalWrite(5, LOW);
      servo1.write(0);
      servo2.write(60);
    }

    else if (inputvalue == 'C') {
      digitalWrite(12, LOW);
      digitalWrite(11, HIGH);
      digitalWrite(10, HIGH);
      digitalWrite(9, LOW);
    }

    else if (inputvalue == 'A') {
      digitalWrite(12, HIGH);
      digitalWrite(11, LOW);
      digitalWrite(10, LOW);
      digitalWrite(9, HIGH);
    }

      else if (inputvalue=='W'){
      digitalWrite(5, HIGH);
      servo1.write(120);
      delay(150);
      servo2.write(0);
      }
      else if (inputvalue=='w'){
        digitalWrite(5, HIGH);
      servo1.write(0);
      delay(150);
      digitalWrite(5, LOW);
      servo2.write(0);
      }
      else if (inputvalue=='U'){
        digitalWrite(5, HIGH);
      servo2.write(120);
      delay(150);
      digitalWrite(5, LOW);
      servo1.write(0);
      }
      else if (inputvalue=='u'){
        digitalWrite(5, HIGH);
      servo1.write(0);
      delay(150);
      digitalWrite(5, LOW);
      servo2.write(0);
      }
      else if (inputvalue=='V'){
        digitalWrite(5, HIGH);
      digitalWrite(6, HIGH);
        Serial.print("Buzzer ON");

      delay(150);
      digitalWrite(6, LOW);
      digitalWrite(5, LOW);
      delay(150);
      digitalWrite(6, HIGH);
      digitalWrite(5, HIGH);
      }
      else if (inputvalue=='v'){
      digitalWrite(5, HIGH);
      digitalWrite(6, LOW);
      Serial.print("Buzzer OFF");
      digitalWrite(5, LOW);
      }

    else if (inputvalue == 'S') {
      digitalWrite(5, LOW);
      servo1.write(0);
      servo2.write(0);
      digitalWrite(12, LOW);
      digitalWrite(11, LOW);
      digitalWrite(10, LOW);
      digitalWrite(9, LOW);
      delay(90);
      digitalWrite(5, HIGH);
      digitalWrite(6, LOW);
     
      delay(90);
      digitalWrite(5, LOW);
      
    }
  }
}