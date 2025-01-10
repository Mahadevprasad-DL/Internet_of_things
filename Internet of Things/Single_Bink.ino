void setup() {
    pinMode(2, OUTPUT);  # pin mood
}

void loop() {
    digitalWrite(2, HIGH);
    delay(2000);
    digitalWrite(2, LOW);
    delay(1000);
}