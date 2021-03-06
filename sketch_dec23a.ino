#include <Wire.h>
#include <LiquidCrystal_I2C.h>
//#define LED 13
int level_1   = A1;
int level_2   = A2;
int level_3   = A3;
int level_4   = A4;
int level_5   = A5;
int pin_motor = 8;
int a;
int b;
int c;
int d;
int e;
int r; //Water Pump status
int z=100; 


LiquidCrystal_I2C lcd(0x27,2,1,0,4,5,6,7,3, POSITIVE);  // Set the LCD I2C address

void setup() {
  // put your setup code here, to run once:
  //pinMode(LED,OUTPUT);
  pinMode(level_1,INPUT);
  pinMode(level_2,INPUT);
  pinMode(level_3,INPUT);
  pinMode(level_4,INPUT);
  pinMode(level_5,INPUT);
  pinMode(pin_motor,OUTPUT);
  digitalWrite(pin_motor,LOW);


  lcd.begin(16,2);
 // lcd.clear();
  //lcd.print("Water Level Monitoring");
  
}

void loop() {
r=digitalRead(pin_motor);
a=analogRead(level_1);
b=analogRead(level_2);
c=analogRead(level_3);
d=analogRead(level_4);
e=analogRead(level_5);
lcd.clear();
lcd.setCursor(0,0);              
lcd.print("MORY");   
lcd.setCursor(0,1);              
lcd.print("Water Level ");
if(e>z && d>z && c>z && b>z && a>z )
{
  digitalWrite(pin_motor,HIGH);
  lcd.setCursor(0,0);
  lcd.print("Tank is 100% FULL");
}
if(e<z && d>z && c>z && b>z && a>z )
{
  lcd.setCursor(0,0);
  lcd.print("Tank is 80% FULL");
}
else if(e<z && d<z && c>z && b>z && a>z )
{
  lcd.setCursor(0,0);
  lcd.print("Tank is 60% FULL");
}
else if(e<z && d<z && c<z && b>z && a>z )
{
  lcd.setCursor(0,0);
  lcd.print("Tank is 40% FULL   ");
}
else if(e<z && d<z && c<z && b<z && a>z )
{
  lcd.setCursor(0,0);
  lcd.print("Tank is 20% FULL");
}

else if(e<z && d<z && c<z && b<z && a<z )
{
  digitalWrite(pin_motor,LOW);
  lcd.setCursor(0,0);
  lcd.print("Tank is EMPTY   ");
}


if(r==LOW)
{
  lcd.setCursor(0,1);
  lcd.print("Pump is (ON)     ");
}
else
{
  lcd.setCursor(0,1);
  lcd.print("Pump is (OFF)      ");
}

  delay(100);
  lcd.clear();

}
