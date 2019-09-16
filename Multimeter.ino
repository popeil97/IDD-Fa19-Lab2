#include <LiquidCrystal.h>


int sensorPin = A0;    // select the input pin for the potentiometer
int ledPin = 13;      // select the pin for the LED
int sensorValue = 0;  // variable to store the value coming from the sensor
int prevSensorValue = 0;
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup() {
  // declare the ledPin as an OUTPUT:
  Serial.begin (9600);
  Serial.println("Start");
}

void loop() {
  // read the value from the sensor:
  sensorValue = analogRead(sensorPin);
  // turn the ledPin on

  if(sensorValue != prevSensorValue) {
    Serial.println("Sensor:");
    Serial.println(sensorValue);
    Serial.println("Prev:");
    Serial.println(prevSensorValue);
    lcd.clear();
    lcd.print(sensorValue);
    lcd.print("V");
    
   }

   prevSensorValue = sensorValue;
}
