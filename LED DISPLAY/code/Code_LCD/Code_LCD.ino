#include <LiquidCrystal.h>
LiquidCrystal lcd (12, 11, 5, 4, 3, 2);
// your PWM numbers may be different 

void setup()  {
  lcd.begin(16,  2);
  lcd.print("put your message here");
}
void loop ()  {
  lcd.setCursor(0, 1);
  lcd.print(millis()/ 1000);
}
