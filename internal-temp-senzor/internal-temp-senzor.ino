//Read the temp from internal temp sensor on rPi Pico
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.printf("Core temperature: %2.1fC\n", analogReadTemp());
  delay(5000);
}
