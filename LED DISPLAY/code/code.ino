#include "DHT.h"
#include <Servo.h>
#define dht_1 2
#define DHTTYPE DHT11

DHT dht(dht_1, DHTTYPE);
Servo sm1, sm2, sm3;
int pos = 0;
void setup() {
//  sm1.attach(13);  
  Serial.begin(9600);
  dht.begin();
}

void loop() {
  delay(2000);

  float humid = dht.readHumidity();
  float temp = dht.readTemperature();

//  if (humid > 30){
//    while(1){
//        if (humid <= 30) break;
//        for (pos = 0; pos <= 180; pos += 1) { // goes from 0 degrees to 180 degrees
//        // in steps of 1 degree
//        sm1.write(pos);         
//        sm2.write(pos);
//        sm3.write(pos);     
//        delay(10);                       // waits 15 ms for the servo to reach the position
//      }
//      for (pos = 180; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
//        sm1.write(pos);         
//        sm2.write(pos);
//        sm3.write(pos); 
//        delay(10);                       // waits 15 ms for the servo to reach the position
//      }
//        Serial.begin(9600);
//        dht.begin();
//    }
//  }
  Serial.println("Humidity : ");
  Serial.println(humid);
  Serial.println("Temperature : ");
  Serial.println(temp);
  Serial.println("Degree centigrade : ");
}
