// Include header files
#include "SR04.h"
#include <LiquidCrystal.h>


// Define Pins
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

int duration = 500;
int buzzer = 5;

int distance[] = {50, 40, 30, 20, 10, 5};
int numDistances = sizeof(distance) / sizeof(distance[0]);

void setup() {
  // LCD
  lcd.clear();
  lcd.begin(16, 2);
  delay(1000);

  // LED
  pinMode(RED, OUTPUT);

  // Buzzer
  pinMode (buzzer, OUTPUT) ;
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

  // Distances
  for (int i = 0; i < numDistances; i++)
  {
    if (a <= distance[i]) {
      switch (distance[i]) {
        case 50:
        
          for (int x = 0; x <100; x++) // When a frequency sound
          {
            digitalWrite (buzzer, HIGH) ; //send tone
            delay (1) ;
            digitalWrite (buzzer, LOW) ; //no tone
            delay (1) ;
          }
          digitalWrite(RED, HIGH);
          redValue = 250;  
          digitalWrite(RED, HIGH); 
          delay(1000); 
          digitalWrite(RED, LOW);
          delay(1000);
          break;
      }
      break;
    } else {
      digitalWrite(RED, LOW);
    }
  }
  
}


