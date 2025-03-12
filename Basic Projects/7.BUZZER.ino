const int buzzerPin = 9; // Pin where the buzzer is connected

void setup() {
  pinMode(buzzerPin, OUTPUT); // Set the buzzer pin as an output
}

void loop() {
  tone(buzzerPin, 500); // Send 500Hz sound signal to buzzer
  delay(500);           // Wait for 0.5 second
  noTone(buzzerPin);    // Stop the sound
  delay(500);           // Wait for 0.5 second
  
  tone(buzzerPin, 1000); // Send 1kHz sound signal to buzzer
  delay(500);            // Wait for 0.5 second
  noTone(buzzerPin);     // Stop the sound
  delay(500);            // Wait for 0.5 second
  
  tone(buzzerPin, 1500); // Send 1.5kHz sound signal to buzzer
  delay(500);            // Wait for 0.5 second
  noTone(buzzerPin);     // Stop the sound
  delay(500);            // Wait for 0.5 second
}