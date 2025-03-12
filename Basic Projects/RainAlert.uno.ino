const int rainSensorPin = 13;
const int buzzerPin = 7;     


void setup() {
  Serial.begin(9600);
  
  pinMode(rainSensorPin, INPUT);
  pinMode(buzzerPin, OUTPUT);

  
  digitalWrite(buzzerPin, LOW);
}

void loop() {
  
  int sensorValue = digitalRead(rainSensorPin);
  
  if (sensorValue == LOW) {
    Serial.println("Rain detected!");
    digitalWrite(buzzerPin, HIGH);

  } 
  else {
    Serial.println("No rain.");
    digitalWrite(buzzerPin, LOW);

  }
  
  delay(1000);
}