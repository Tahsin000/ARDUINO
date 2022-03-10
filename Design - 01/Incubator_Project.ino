#include <LiquidCrystal.h>
#include<TimerOne.h>
LiquidCrystal lcd(11, 10, 6, 5, 4, 3);

#define   Heater  2
#define   Cooler  8
#define   Fan     12
#define   Buzzer  7
#define   Turning 9

#define   Heater_ON   digitalWrite(Heater,HIGH);
#define   Heater_OFF  digitalWrite(Heater,LOW);
#define   Cooler_ON   digitalWrite(Cooler,HIGH);
#define   Cooler_OFF  digitalWrite(Cooler,LOW);
#define   Fan_ON      digitalWrite(Fan,HIGH);
#define   Fan_OFF     digitalWrite(Fan,LOW);
#define   Turning_ON  digitalWrite(Turning,HIGH);
#define   Turning_OFF digitalWrite(Turning,LOW);
#define   Buzzer_ON   digitalWrite(Buzzer,HIGH);
#define   Buzzer_OFF  digitalWrite(Buzzer,LOW);

#include "DHT.h"
#define DHTPIN 13
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);
float Temperature = 0;
float Setpoint = 0;
unsigned int timer_counter = 0;
unsigned int counter1 = 0;


void setup()
{
  pinMode(Heater, OUTPUT);
  pinMode(Cooler, OUTPUT);
  pinMode(Fan, OUTPUT);
  pinMode(Buzzer, OUTPUT);
  pinMode(Turning, OUTPUT);
  lcd.begin(16, 2);
  lcd.setCursor(0, 0);//cr
  lcd.print("Egg Incubator");
  Buzzer_ON;
  delay(100);
  Buzzer_OFF;
  dht.begin();
  delay(2000);
  lcd.clear();
  Timer1.initialize(100000); 
  Timer1.attachInterrupt( timerIsr );
  lcd.clear();
}

void loop()
{

  Read_temp();
  Read_setpoint();
  PrintTemp();
  Read_DHT11();
  Temperature_control();

}

void timerIsr()
{
  //Turning control
  timer_counter++;
  if (timer_counter > 16200 && timer_counter < 16500)
  {
    Turning_ON;
  }
  else
  {
    Turning_OFF;
  }

  if (timer_counter > 16500)
  {
    timer_counter = 0;
  }

}

void Temperature_control()
{
  if (Temperature >= Setpoint + 0.5)
  {
    Heater_OFF;
    counter1++;
    if (counter1 > 20)
    {
      counter1 = 0;
      if (Fan == HIGH)
      {
        Fan_OFF;
      }
      else if (Fan == LOW)
      {
        Fan_ON;
      }
    }

    if (Temperature >= Setpoint + 1.5)
    {
      Cooler_ON;
    }
    else if (Temperature <= Setpoint + 0.5)
    {
      Cooler_OFF;
    }

    if (Temperature >= Setpoint + 2.0)
    {
      Buzzer_ON;
    }
    else
    {
      Buzzer_OFF;
    }
  }
  else if (Temperature <= Setpoint - 0.5)
  {
    Heater_ON;
    Fan_ON;
    Cooler_OFF;
    if (Temperature <= Setpoint - 1.0)
    {
      Buzzer_ON;
    }
    else
    {
      Buzzer_OFF;
    }
  }
}
void Read_temp()
{
  Temperature = 0;
  for (int i = 0; i < 30; i++)
  {
    Temperature += analogRead(A1) * 0.5;
    delay(10);
  }
  Temperature /= 30;
  Temperature;
}

void Read_setpoint()
{
  Setpoint = 0;
  for (int i = 0; i < 30; i++)
  {
    Setpoint += analogRead(A0) / 25.6;
    delay(2);
  }
  Setpoint /= 30;
}

void PrintTemp()
{
  lcd.setCursor(9, 0);//cr
  lcd.write("S:");
  lcd.print(Setpoint, 1);

  lcd.setCursor(0, 0);//cr
  lcd.write("T:");
  lcd.print(Temperature-1, 1);
  lcd.write((char)223);
  lcd.write("C");
}

void Read_DHT11()
{
  float h = dht.readHumidity();

  lcd.setCursor(0, 1);//cr
  lcd.write("H:");
  lcd.print(h);
  lcd.write("%");

  lcd.setCursor(9, 1);//cr
  lcd.write("S:");
  lcd.print("86%");
}

//
