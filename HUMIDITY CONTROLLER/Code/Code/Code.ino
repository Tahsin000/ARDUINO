#include "DHT.h"
#include <LiquidCrystal.h>
#define dht_1 2
#define DHTTYPE DHT11
LiquidCrystal lcd (12, 11, 7, 6, 5, 4);

DHT dht(dht_1, DHTTYPE);
int FAN = 13;
void setup() {
  pinMode(FAN, OUTPUT);
  Serial.begin(9600);
  dht.begin();
}

void loop() {
  delay(800);

  float humid = dht.readHumidity();
  float temp = dht.readTemperature();
  if (humid > 60)
    digitalWrite(FAN, HIGH);
 
  else digitalWrite(FAN, LOW);
  lcd.begin(16,  2);
  lcd.print("Humidity : ");
  lcd.print(humid);
  lcd.setCursor(0, 1);
  lcd.print("Temperature : ");
  lcd.print(temp);
//  Serial.println("Humidity : ");
//  Serial.println(humid);
//  Serial.println("Temperature : ");
//  Serial.println(temp);
//  Serial.println("Degree centigrade : ");
}
