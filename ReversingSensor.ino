#include "SR04.h"
#include <LiquidCrystal.h>
#define TRIG_PIN 53
#define ECHO_PIN 51
SR04 sr04 = SR04(ECHO_PIN,TRIG_PIN);
long a;
String aString;

LiquidCrystal lcd(7, 8, 9, 10, 11, 12);
void setup() {
   Serial.begin(9600);
   lcd.clear();
   lcd.begin(16, 2);
   delay(1000);
}

void loop() {
  lcd.setCursor(0, 0);
   a=sr04.Distance();
   lcd.print("Distance: ");
   lcd.setCursor(10,0);
   lcd.print(a);
   aString = String(a);
   int length = aString.length();
   lcd.setCursor(length + 10, 0);
   lcd.print("cm");
   lcd.print("    ");
   delay(500);
}
