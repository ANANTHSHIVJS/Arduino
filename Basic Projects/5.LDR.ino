#include <Wire.h>
#include <RTClib.h>
#include <LiquidCrystal_I2C.h>

RTC_DS3231 rtc;
LiquidCrystal_I2C lcd(0x27, 16, 2);

const int setTimeButton = 2;
const int setAlarmButton = 3;
const int increaseButton = 4;   
const int decreaseButton = 5;
const int buzzer = 6;

DateTime alarmTime;
bool alarmSet = false;

void setup() {
  pinMode(setTimeButton, INPUT);
  pinMode(setAlarmButton, INPUT);
  pinMode(increaseButton, INPUT);
  pinMode(decreaseButton, INPUT);
  pinMode(buzzer, OUTPUT);

  lcd.begin();
  lcd.backlight();

  if (!rtc.begin()) {
    lcd.print("Couldn't find RTC");
    while (1);
  }

  if (rtc.lostPower()) {
    lcd.print("RTC lost power");
    rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
  }

  alarmTime = DateTime(0, 1, 1, 0, 0, 0); // Default alarm time (00:00:00)
}

void loop() {
  DateTime now = rtc.now();

  lcd.setCursor(0, 0);
  lcd.print("Time: ");
  printTime(now);

  lcd.setCursor(0, 1);
  if (alarmSet) {
    lcd.print("Alarm: ");
    printTime(alarmTime);
  } else {
    lcd.print("Alarm: --:--:--");
  }

  if (digitalRead(setTimeButton) == HIGH) {
    setTime();
  }

  if (digitalRead(setAlarmButton) == HIGH) {
    setAlarm();
  }

  if (alarmSet && now.hour() == alarmTime.hour() && now.minute() == alarmTime.minute() && now.second() == alarmTime.second()) {
    tone(buzzer, 1000); // Buzz
  } else {
    noTone(buzzer);
  }

  delay(1000);
}

void printTime(DateTime time) {
  if (time.hour() < 10) lcd.print('0');
  lcd.print(time.hour());
  lcd.print(':');
  if (time.minute() < 10) lcd.print('0');
  lcd.print(time.minute());
  lcd.print(':');
  if (time.second() < 10) lcd.print('0');
  lcd.print(time.second());
}

void setTime() {
  int hour = rtc.now().hour();
  int minute = rtc.now().minute();

  while (digitalRead(setTimeButton) == HIGH) {
    if (digitalRead(increaseButton) == HIGH) {
      hour = (hour + 1) % 24;
      delay(200);
    }
    if (digitalRead(decreaseButton) == HIGH) {
      hour = (hour - 1 + 24) % 24;
      delay(200);
    }
    lcd.setCursor(0, 1);
    lcd.print("Set Time: ");
    lcd.print(hour < 10 ? "0" : "");
    lcd.print(hour);
    lcd.print(":");
    lcd.print(minute < 10 ? "0" : "");
    lcd.print(minute);
  }

  while (digitalRead(setTimeButton) == HIGH) {
    if (digitalRead(increaseButton) == HIGH) {
      minute = (minute + 1) % 60;
      delay(200);
    }
    if (digitalRead(decreaseButton) == HIGH) {
      minute = (minute - 1 + 60) % 60;
      delay(200);
    }
    lcd.setCursor(0, 1);
    lcd.print("Set Time: ");
    lcd.print(hour < 10 ? "0" : "");
    lcd.print(hour);
    lcd.print(":");
    lcd.print(minute < 10 ? "0" : "");
    lcd.print(minute);
  }

  rtc.adjust(DateTime(rtc.now().year(), rtc.now().month(), rtc.now().day(), hour, minute, 0));
}

void setAlarm() {
  int hour = alarmTime.hour();
  int minute = alarmTime.minute();

  while (digitalRead(setAlarmButton) == HIGH) {
    if (digitalRead(increaseButton) == HIGH) {
      hour = (hour + 1) % 24;
      delay(200);
    }
    if (digitalRead(decreaseButton) == HIGH) {
      hour = (hour - 1 + 24) % 24;
      delay(200);
    }
    lcd.setCursor(0, 1);
    lcd.print("Set Alarm: ");
    lcd.print(hour < 10 ? "0" : "");
    lcd.print(hour);
    lcd.print(":");
    lcd.print(minute < 10 ? "0" : "");
    lcd.print(minute);
  }

  while (digitalRead(setAlarmButton) == HIGH) {
    if (digitalRead(increaseButton) == HIGH) {
      minute = (minute + 1) % 60;
      delay(200);
    }
    if (digitalRead(decreaseButton) == HIGH) {
      minute = (minute - 1 + 60) % 60;
      delay(200);
    }
    lcd.setCursor(0, 1);
    lcd.print("Set Alarm: ");
    lcd.print(hour < 10 ? "0" : "");
    lcd.print(hour);
    lcd.print(":");
    lcd.print(minute < 10 ? "0" : "");
    lcd.print(minute);
  }

  alarmTime = DateTime(0, 1, 1, hour, minute, 0);
  alarmSet = true;
}
