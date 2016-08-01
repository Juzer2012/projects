#include <PCF8814.h>

static const byte ledPin = 13;
static const byte LCD_WIDTH = 96;
static const byte LCD_HEIGHT = 65;
static PCF8814 lcd;

void setup() {
  lcd.begin(LCD_HEIGHT, LCD_WIDTH);
  pinMode(ledPin, OUTPUT);
  lcd.print("The LCD Totally Works!");
  delay(5000);
  lcd.clear();
}


void loop() {
  lcd.setCursor(0, 0);
  lcd.print("THIS IS JUZER");
  lcd.setCursor(40, 1);
  lcd.print("HELLO");
  lcd.setCursor(0, 2);
  lcd.print("FRIENDS");
  delay(5000);
}
