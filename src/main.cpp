
// In this small projrct An Altrasonic Sensor is used to measure the position of an object and print the time it takes to reach that object in Microsecond
// Also the distance betwenn the oject and the Sensor is used to turn a buzer all controlled by an ESP32 
// The main objectif of the project is to implement a simple example of RTOS
#include <Arduino.h>
#include<RTOS.h>
const int triger_Pin = 2;  // Set the triger pin of the Ultrasonic sensor
const int Echo_pin   = 4                 ;  // Set the echo pin of the Ultrasonic Sensor
int TravelTime;             // The traveling time
void setup() {
  // put your setup code here, to run once:
  pinMode(triger_Pin, OUTPUT);
  pinMode(Echo_pin, INPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  // The echo pin starts listening only if the triger pin is low.
  digitalWrite(triger_Pin, LOW);               
  vTaskDelay(10/portTICK_PERIOD_MS);
  digitalWrite(triger_Pin, HIGH);
  vTaskDelay(10/portTICK_PERIOD_MS);
  digitalWrite(triger_Pin, LOW);        // Set the triger pin Low and let the echo pin listen and print the travel time using pulseIn
  TravelTime = pulseIn(Echo_pin, HIGH);
 vTaskDelay(100/portTICK_PERIOD_MS);
  Serial.println(TravelTime);
}