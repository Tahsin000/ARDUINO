#include "DHT.h"
#include <LiquidCrystal.h>
#define dht_1 2
#define DHTTYPE DHT22
int Contrast = 75;
LiquidCrystal lcd(12, 11, 7, 5, 4, 3);
DHT dht(dht_1, DHTTYPE);
int FAN = 13;
int light = 8;
volatile byte relayState = LOW;
void setup()
{
    pinMode(FAN, OUTPUT);
    pinMode(light, OUTPUT);
    Serial.begin(9600);
    analogWrite(6, Contrast);
    lcd.begin(16, 2);
    dht.begin();
}

void loop()
{
    delay(250);

    float humid = dht.readHumidity();
    float temp = dht.readTemperature();
    if (humid <= 50)
        digitalWrite(FAN, LOW);
    if (humid > 60)
        digitalWrite(FAN, HIGH);
    if (temp >= 38)
    {
        if (temp >= 40)
        {
            digitalWrite(light, LOW);
        }
        else
        {
            digitalWrite(light, HIGH);
        }
    }
    if (temp < 34)
    {
        if (temp < 32)
        {
            digitalWrite(light, HIGH);
        }
        else
        {
            digitalWrite(light, LOW);
        }
    }

    lcd.setCursor(0, 0);
    lcd.print("Humidity : ");
    lcd.print(humid);
    lcd.setCursor(0, 1);
    lcd.print("Temp : ");
    lcd.print(temp);
}
