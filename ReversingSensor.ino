// Include header files
#include "SR04.h"
#include <LiquidCrystal.h>


// Define Pinsg
#define TRIG_PIN 53
#define ECHO_PIN 51
#define BLUE 3
#define GREEN 2
#define RED 4

SR04 sr04 = SR04(ECHO_PIN, TRIG_PIN);
LiquidCrystal lcd(7, 8, 9, 10, 11, 12);

String aString;
long a;
int redValue;
const int buzzerPin = 5;

// array containing the distances
// int distance[] = {50, 40, 30, 20, 10, 5};
// int numDistances = sizeof(distance) / sizeof(distance[0]);


void setup() {
  // LCD
  lcd.clear();
  lcd.begin(16, 2);
  delay(1000);

  // LED
  pinMode(RED, OUTPUT);

  // Buzzer
  pinMode (buzzerPin, OUTPUT) ;


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


  if (a <= 50 && a > 40) {
    
    tone(buzzerPin, 800,30); //send tone
    
    digitalWrite(RED, HIGH);
    
    digitalWrite(RED, HIGH); 
    delay(250); 
    digitalWrite(RED, LOW);
    delay(250);
    noTone(buzzerPin);
  }
  if (a <= 40 && a > 30) {
    tone(buzzerPin, 800,30); //send tone
    
    digitalWrite(RED, HIGH);
    
    digitalWrite(RED, HIGH); 
    delay(150); 
    digitalWrite(RED, LOW);
    delay(150);
    noTone(buzzerPin);
  
  }
  if (a <= 30 && a > 20) {
    tone(buzzerPin, 800,30); //send tone
    
    digitalWrite(RED, HIGH);
    
    digitalWrite(RED, HIGH); 
    delay(50); 
    digitalWrite(RED, LOW);
    delay(50);
    noTone(buzzerPin);
  }
  if (a <= 20 && a > 15) {
    tone(buzzerPin, 800); //send tone
    
    digitalWrite(RED, HIGH);
    
    digitalWrite(RED, HIGH); 
    delay(10); 
    digitalWrite(RED, LOW);
    delay(10);
    noTone(buzzerPin);
  }
  if (a < 15) {
    while (a < 15) {
      tone(buzzerPin, 800); //send tone
        
      digitalWrite(RED, HIGH); 
      a = sr04.Distance();
    }
  }
  else {
  digitalWrite(RED, LOW);
  noTone(buzzerPin);
  }
}


