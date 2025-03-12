// Define the pins
const int tempSensorPin = A0; // Analog pin for temperature sensor
const int buzzerPin = 8;      // Digital pin for buzzer

// Temperature threshold in degrees Celsius
const float temperatureThreshold = 19.0;

void setup() {
  // Initialize serial communication for debugging
  Serial.begin(9600);
  
  // Set the buzzer pin as output
  pinMode(buzzerPin, OUTPUT);
  
  // Ensure the buzzer is off initially
  digitalWrite(buzzerPin, LOW);
}

void loop() {
  // Read the analog value from the temperature sensor.
  int sensorValue = analogRead(tempSensorPin);
  
  // Convert the analog value to temperature in Celsius
  // LM35 gives 10mV per degree Celsius. 
  // Analog reading is from 0 to 1023, corresponding to 0 to 5V.
  float temperature = sensorValue * (3.0 / 1023.0) * 10;
  
  // Print the temperature for debugging
  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.println(" *C");
  
  // Check if the temperature exceeds the threshold
  if (temperature > temperatureThreshold) {
    // Turn on the buzzer
    tone(buzzerPin,1000);
  } else {
    // Turn off the buzzer
    noTone(buzzerPin);
  }
  
  // Wait for a short period before reading again
  delay(1000);
}