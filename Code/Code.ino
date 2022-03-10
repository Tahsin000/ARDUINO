/* Sweep
 by BARRAGAN <http://barraganstudio.com>
 This example code is in the public domain.

 modified 8 Nov 2013
 by Scott Fitzgerald
 https://www.arduino.cc/en/Tutorial/LibraryExamples/Sweep
*/

#include <Servo.h>

Servo sm1, sm2, sm3;  // create servo object to control a servo
// twelve servo objects can be created on most boards

int pos = 0;    // variable to store the servo position

void setup() {
  sm1.attach(13);  
  sm2.attach(12);  
  sm3.attach(11);  
}

void loop() {
  for (pos = 0; pos <= 180; pos += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    sm1.write(pos);         
    sm2.write(pos);
    sm3.write(pos);     
    delay(15);                       // waits 15 ms for the servo to reach the position
  }
  for (pos = 180; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
    sm1.write(pos);         
    sm2.write(pos);
    sm3.write(pos); 
    delay(15);                       // waits 15 ms for the servo to reach the position
  }
}
