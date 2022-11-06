//read all available analog pins on rpi pico with analog correction
#include <Arduino.h>
#include <PicoAnalogCorrection.h>

const uint8_t ADC0 = A0;
const uint8_t ADC1 = A1;
const uint8_t ADC2 = A2;
const uint8_t GND_PIN = 15;
const uint8_t VCC_PIN = 16;
const uint8_t ADC_RES = 12; // ADC bits

PicoAnalogCorrection pico(ADC_RES);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600); 
  pinMode(ADC0,INPUT);
  pinMode(ADC1,INPUT);
  pinMode(ADC2,INPUT); 
  pinMode(GND_PIN,INPUT);
  pinMode(VCC_PIN,INPUT); 

  analogReadResolution(ADC_RES);

  // Calibrate ADC using an average of 5000 measurements
  pico.calibrateAdc(GND_PIN, VCC_PIN, 5000);
}

void loop() {
  Serial.printf("ADC0: %d, ADC1: %d, ADC2: %d \n", analogRead(ADC0),analogRead(ADC1),analogRead(ADC2));
  Serial.printf("pico.ADC0: %d, pico.ADC1: %d, pico.ADC2: %d \n", pico.analogRead(ADC0),pico.analogRead(ADC1),pico.analogRead(ADC2));
  Serial.printf("picoC.ADC0: %d, picoC.ADC1: %d, picoC.ADC2: %d \n", pico.analogCRead(ADC0,10),pico.analogCRead(ADC1,10),pico.analogCRead(ADC2,10));

  delay(5000);

}
