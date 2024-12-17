// Areesh Nadeem, netID: anade2
// Adrian Silva, netID: asilv5
// Project Name: Water Leak Detector 
// Sensor Arduino
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

#define SIGNAL_PIN A5 // water sensor analog pin
int sensorVal = 0;

unsigned long prevMillis = 0;
const int threshold = 200; 

void setup() {

  // serial communication with Alert Arduino
  Serial.begin(9600);
}

void loop() {
    
    if (millis() - prevMillis >= 300) {
        prevMillis = millis();

        // Read the value of the analog sensor
        sensorVal = analogRead(SIGNAL_PIN);

        // Serial.println(sensorVal); // for debugging

        // check if the sensor value is above the threshold
        if (sensorVal >= threshold) {
            // LEAK detected, send signal to Alert Arduino
            Serial.write('L'); 
        } 
        
        else {
            // Send a signal indicating no leak detected
            Serial.write('N');
        }

    }
}
