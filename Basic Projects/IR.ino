const int irPin = 2;  // Pin connected to the IR sensor
const int ledPin = 9; // Pin connected to the LED
int irValue = 0;      // Variable to store the IR sensor value

void setup() {
  // Start the serial communication
  Serial.begin(9600);

  // Set the IR pin as an input
  pinMode(irPin, INPUT);
  
  // Set the LED pin as an output
  pinMode(ledPin, OUTPUT);
}



void loop() {
  // Read the value from the IR sensor
  irValue = digitalRead(irPin);

  // Print the IR sensor value to the Serial Monitor
  Serial.print("IR Value: ");
  Serial.println(irValue);

  // If the IR sensor detects an object (value is LOW), turn the LED on
  // Otherwise, turn the LED off
  if (irValue == LOW) {
    digitalWrite(ledPin, HIGH); // Turn LED on
  } else {
    digitalWrite(ledPin, LOW);  // Turn LED off
  }

  // Wait for a short period before reading again
  delay(100);
}

