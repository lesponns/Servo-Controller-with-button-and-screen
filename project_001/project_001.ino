#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <Servo.h>
Servo myservo;

LiquidCrystal_I2C lcd(0x27, 16, 2); // LCD adresi ve 2 satır
int cursorPosition = 0, Imlec = 0, stage8 = 0, stage9 = 0, yuzdeSira = 11, yuzdeSatir = 0, servoAngle = 0; // İmleç konumunu takip etmek için değişken

void setup() 
{
  lcd.init();
  lcd.backlight();
  pinMode(8, INPUT_PULLUP);
  pinMode(9, INPUT_PULLUP);
  myservo.attach(10);
  myservo.write(servoAngle);
  for (int i = 0; i < 16; i++)
  {
    lcd.setCursor(i,0);
    lcd.print("POYRAZ");
    delay(300);
    lcd.setCursor(i,0);
    lcd.print(" ");
  }
  lcd.print("               ");
  delay(1000);
  lcd.setCursor(0, 0);
  lcd.print("MENU");
}

void loop() {
  if (digitalRead(8) == LOW)
  {
    if (stage8 == 0){
      lcd.setCursor(0, 0);
      lcd.print("ENJECTION:");
      stage8 = 1;
      lcd.setCursor(12, 1);
      lcd.print("                ");
      delay(500);
    }
    else if (stage8 == 1){
      lcd.setCursor(0, 0);
      lcd.print("                ");
      stage8 = 0;
      lcd.setCursor(0, 0);
      lcd.print("Working...");
      delay(500);
      lcd.setCursor(0,0);
      lcd.print("               ");
      delay(500);
      lcd.setCursor(0,0);
      lcd.print("MENU");
      delay(500);

      for (int i = 0; i < 180; i++)
      {
        if (servoAngle == i){
          myservo.write(i);
          break;
        }
      }
    } 
  }
    if (digitalRead(9) == LOW){
      if(stage8 == 1){
        if (stage9 == 0){
          lcd.setCursor(yuzdeSira, yuzdeSatir);
          lcd.print("%0  ");
          servoAngle = 0;
          stage9 = stage9 + 45;
          delay(200);
        }
        else if (stage9 == 45){
          lcd.setCursor(yuzdeSira, yuzdeSatir);
          lcd.print("%25 ");
          servoAngle = 45;
          stage9 = stage9 + 45;
          delay(200);
        }
        else if (stage9 == 90){
          lcd.setCursor(yuzdeSira, yuzdeSatir);
          lcd.print("%50 ");
          servoAngle = 90;
          stage9 = stage9 + 45;
          delay(200);
        }
        else if (stage9 == 135){
          lcd.setCursor(yuzdeSira, yuzdeSatir);
          lcd.print("%75 ");
          servoAngle = 135;
          stage9 = stage9 + 45;
          delay(200);
        }
        else if (stage9 == 180){
          lcd.setCursor(yuzdeSira, yuzdeSatir);
          lcd.print("%100");
          servoAngle = 179;
          stage9 = 0;
          delay(200);
        }
      }
    }
  
}
// ### Coded by Lesponns. ### //