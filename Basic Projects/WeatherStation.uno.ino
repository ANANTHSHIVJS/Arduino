// Pin Definitions
const int rainSensorPin = 13;   // Rain sensor connected to digital pin D2
const int ldrPin = 12;          // LDR connected to digital pin D3
const int ledPin = 6;          // LED connected to digital pin D5
const int buzzerPin = 7;       // Buzzer connected to digital pin D6

void setup() {
  // Initialize pins
  pinMode(rainSensorPin, INPUT);  // Rain sensor as input
  pinMode(ldrPin, INPUT);         // LDR as input
  pinMode(ledPin, OUTPUT);        // LED as output
  pinMode(buzzerPin, OUTPUT);     // Buzzer as output

  // Initialize serial communication for debugging
  Serial.begin(9600);
}

void loop() {
  // Read rain sensor state
  int rainDetected = digitalRead(rainSensorPin);
  Serial.print("Rain Detected: ");
  Serial.println(rainDetected);

  // Read LDR state
  int isLight = digitalRead(ldrPin);
  Serial.print("Light Detected: ");
  Serial.println(isLight);

  // If rain is detected, activate buzzer and LED
  if (rainDetected == HIGH) {  // Assume LOW means rain detected, adjust if needed
    digitalWrite(buzzerPin, LOW);  // Turn on buzzer
  } else {
    digitalWrite(buzzerPin, HIGH);   // Turn off buzzer
  }
    if (isLight == HIGH) {          // Assume HIGH means enough light detected
      digitalWrite(ledPin, LOW);    // Turn off LED if it's bright enough;
    } else {
      digitalWrite(ledPin, HIGH);   // Keep LED on if it's darkd    }
  

  // Delay to avoid spamming the serial monitor
  delay(5000);
}
}
