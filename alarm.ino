#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 2, 16);

const int PIN_TO_SENSOR = 2;   
int pinStateCurrent   = LOW; 
int pinStatePrevious  = LOW; 

void setup() {
  lcd.init();         
  lcd.init();
  lcd.backlight();
  Serial.begin(9600);            
  pinMode(PIN_TO_SENSOR, INPUT); 
}

void loop() {
  pinStatePrevious = pinStateCurrent; 
  pinStateCurrent = digitalRead(PIN_TO_SENSOR);   

  if (pinStatePrevious == LOW && pinStateCurrent == HIGH) {   
    Serial.println("Motion detected!");
    lcd.setCursor(0,0);
    lcd.print("Intruder!!");
    delay(1000);
  }
  else
  if (pinStatePrevious == HIGH && pinStateCurrent == LOW) {  
    Serial.println("Motion stopped!");
    lcd.setCursor(0,0);
    lcd.print("             ");
    delay(1000);
  }
  delay(1000);
}
