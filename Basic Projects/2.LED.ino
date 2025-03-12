// The setup function runs once when you press reset or power the board
void setup() {
  // Initialize digital pin 13 as an output.
  pinMode(7, OUTPUT);
}

// The loop function runs over and over again forever
void loop() {
  digitalWrite(7, HIGH);   // Turn the LED on (HIGH is the voltage level)
  delay(1000);              // Wait for a second
  digitalWrite(7, LOW);    // Turn the LED off by making the voltage LOW
  delay(1000);              // Wait for a second
}