#include <LiquidCrystal.h>
 
#define trigger A4
#define echo A5
 
LiquidCrystal lcd(0, 1, 8, 9, 10, 11);
 
float time=0,distance=0;
 
void setup()
{
 lcd.begin(16,2);
 pinMode(trigger,OUTPUT);
 pinMode(echo,INPUT);
 lcd.print(" Ultra sonic");
 lcd.setCursor(0,1);
 lcd.print("Distance Meter");
}
 
void loop()
{
 lcd.clear();
 digitalWrite(trigger,LOW);
 delayMicroseconds(2);
 digitalWrite(trigger,HIGH);
 delayMicroseconds(10);
 digitalWrite(trigger,LOW);
 delayMicroseconds(2);
 time=pulseIn(echo,HIGH);
 distance=time*340/20000;
 lcd.clear();
 lcd.print("Distance:");
 lcd.print(distance);
 lcd.print("cm");
 lcd.setCursor(0,1);
 lcd.print("Distance:");
 lcd.print(distance/100);
 lcd.print("m");
 delay(1000);
}
