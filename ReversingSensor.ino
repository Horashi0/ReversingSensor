#include "SR04.h"
#include <LiquidCrystal.h>
#define TRIG_PIN 53
#define ECHO_PIN 51
// Define Pins
#define BLUE 3
#define GREEN 2
#define RED 4
SR04 sr04 = SR04(ECHO_PIN, TRIG_PIN);
long a;
String aString;
int redValue;

LiquidCrystal lcd(7, 8, 9, 10, 11, 12);
void setup() {
  // LCD
  lcd.clear();
  lcd.begin(16, 2);
  delay(1000);
  // LED
  pinMode(RED, OUTPUT);
}

void loop() {
  // Distance
  a = sr04.Distance();
  aString = String(a);
  int length = aString.length();
  // LCD
  lcd.setCursor(0, 0);
  lcd.print("Distance: ");
  lcd.setCursor(10, 0);
  lcd.print(a);
  lcd.setCursor(length + 10, 0);
  lcd.print("cm");
  lcd.print("    ");
  delay(500);
  if (a <= 50)
  {
    digitalWrite(RED, HIGH);
    redValue = 250;  
    digitalWrite(RED, HIGH); 
    delay(1000); 
    digitalWrite(RED, LOW);
    delay(1000);
  }
  if (a > 50)
  {
    digitalWrite(RED, LOW);
  }
}
