#include "BluetoothSerial.h"

BluetoothSerial SerialBT;
int received;// received value will be stored in this variable
char receivedChar;// received value will be stored as CHAR in this variable

const char lid_open ='1';
const char lid_close ='0';
int motor1Pin1 = 27; 
int motor1Pin2 = 14; 
int enable1Pin = 12; 
 

 
void setup() {
  Serial.begin(115200);
  SerialBT.begin("Reborn"); //Bluetooth device name
  Serial.println("The device started, now you can pair it with bluetooth!");
  Serial.println("To turn clockwise send: a");//print on serial monitor  
  Serial.println("To turn anticlockwise send: b"); //print on serial monitor 
  // sets the pins as outputs:
  pinMode(motor1Pin1, OUTPUT);
  pinMode(motor1Pin2, OUTPUT);
  pinMode(enable1Pin, OUTPUT);
  

  Serial.begin(115200);
 
  // testing
  //Serial.print("Testing DC Motor...");
}
 
void loop() {

   receivedChar =(char)SerialBT.read();

if(receivedChar == lid_open)
{
   // Move the DC motor Clockwise at maximum speed
  digitalWrite(enable1Pin, HIGH); 
  Serial.println("Open");
  digitalWrite(motor1Pin1, LOW);
  digitalWrite(motor1Pin2, HIGH); 
  delay(3500);
  digitalWrite(enable1Pin, LOW); 
}
if(receivedChar == lid_close)
{
  // Move DC motor Anticlockwise at maximum speed
 
  digitalWrite(enable1Pin, HIGH); 
  Serial.println("Close");
  digitalWrite(motor1Pin1, HIGH);
  digitalWrite(motor1Pin2, LOW); 
  delay(3500);
  digitalWrite(enable1Pin, LOW); 
}
 
  
  }
