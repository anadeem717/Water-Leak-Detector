// Areesh Nadeem, netID: anade2
// Adrian Silva, netID: asilv5
// Project Name: Water Leak Detector 
// Alert Arduino
/* 
Abstract: Our project is a real-time water leak detection system 
using two Arduino  boards to identify and alert users to leaks, 
helping prevent damage. One Arduino monitors for water,  while 
the other activates alarms through LED indicators, a buzzer, and 
an LCD display to notify  users of leaks immediately. The user can 
stop the alarm by pressing a button. The Arduinos will send signals 
using serial communication. Unlike conventional projects that measure 
water levels,  our focus is on rapid leak detection and immediate notification 
to help prevent water-related damage.
*/


#include <LiquidCrystal.h>

// LCD Pins
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

const int ledPin = 9;
const int buzzerPin = 7;
const int buttonPin = 8;

unsigned long prevMillis = 0;
unsigned long toggleMillis = 0; // For LED and buzzer toggling
int ledState = LOW;

bool alarm = false; // if alarm is active or not
bool alarmStopped = false;

#define NOTE_C8 4186 // note for buzzer

void setup() {
    pinMode(ledPin, OUTPUT);
    pinMode(buzzerPin, OUTPUT);
    pinMode(buttonPin, INPUT);

    // Set up the LCD
    lcd.begin(16, 2);

    // serial communication with Sensor Arduino
    Serial.begin(9600);
}

void loop() {

    // check if signal is available from sensor arduino
    if (Serial.available()) {
        char signal = Serial.read();
        Serial.println(signal);

        // process the received signal
        if (signal == 'L' && !alarmStopped) {
            // If 'L' received activate the alarm
            alarm = true;
        } 
        else if (signal == 'N') {
            // If 'N' received, deactivate the alarm
            digitalWrite(ledPin, LOW);
            noTone(buzzerPin);
            alarm = false;
        }
    }

    // Toggle LED and buzzer every 1 second if the alarm is active
    if (alarm && (millis() - toggleMillis >= 1000)) {
        toggleMillis = millis(); // Reset toggle timer

        ledState = !ledState; 
        digitalWrite(ledPin, ledState); // Update LED

        // match timing with LEDs, if LEDs on then buzzer on
        if (ledState) { tone(buzzerPin, NOTE_C8); } 
        else { noTone(buzzerPin); }
    }

    // update LCD every 300 ms
    if (millis() - prevMillis > 300) {
        prevMillis = millis();

        lcd.clear();

        if (alarm) { // if alarm is active
            lcd.setCursor(0, 0); 
            lcd.print("LEAK DETECTED");
            lcd.setCursor(0, 1); 
            lcd.print("BUTTON TO STOP");
        } 

        else if (alarmStopped) { // alarm has been stopped
            lcd.setCursor(0, 0);
            lcd.print("Alarm Stopped");
        } 

        else { // no leak
            lcd.setCursor(0, 0);
            lcd.print("No Leak");
        }
    }

    // check if alarm is active and button is pressed
    // means user stopped the alarm
    if (alarm == true && digitalRead(buttonPin) == HIGH) {

        // turn off alerts
        digitalWrite(ledPin, LOW);
        noTone(buzzerPin);

        alarm = false;
        alarmStopped = true;

        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("Alarm Stopped");
    }
}
