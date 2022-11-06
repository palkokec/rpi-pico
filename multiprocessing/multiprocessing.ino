void setup() {
  // put your setup code here, to run once on core 0:
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly on core 0:
  Serial.printf("Temperature measured by core 0: %2.1fC\n", analogReadTemp());
  delay(5000);
}

void setup1() {
  // put your setup code here, to run once on core 1:
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop1() {
  // put your main code here, to run repeatedly on core 1:
  Serial.printf("Led blinking on core 1\n");
  digitalWrite(LED_BUILTIN, HIGH);
  delay(1000);
  digitalWrite(LED_BUILTIN, LOW);
  delay(4000);
}

