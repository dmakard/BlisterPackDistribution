// Sweep
// by BARRAGAN <http://barraganstudio.com> 
// This example code is in the public domain.

#include <avr/io.h>
#include <util/delay.h>
#include <Servo.h> 
#include <stdint.h>

#define HATCH 3
#define CONT1 4
#define CONT2 12
 
 Servo myservo; 
 int pos = 0;
 bool flag = true;

void setup() {

  servoSweep(4);
  delay(2000);
  servoSweep(3); 
} 

void servoSweep(){
  setup();
  loop();
}


void servoSweep(int servo){
  myservo.attach(servo);  // attaches the servo on pin 9 to the servo object ,PD4567 
  for (pos = 0; pos <= 120; pos += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }
  for (pos = 120; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }
}

int main(){
  while(flag){
    void servoSweep();
  }
}

 
 

