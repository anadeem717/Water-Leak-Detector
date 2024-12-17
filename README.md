# Water Leak Detector

## Abstract

The **Water Leak Detector** is a real-time Arduino-based system designed to identify and alert users to water leaks, helping to prevent damage and costly repairs. This project employs two Arduinos: one monitors for water leaks, while the other manages alarms via LEDs, a buzzer, and an LCD display. The system provides immediate notification and allows users to deactivate the alarm by pressing a button. The Arduinos communicate using serial communication, ensuring accurate and responsive performance. Unlike traditional water measurement systems, this project emphasizes rapid detection and alerting.

---

## Table of Contents

1. [Project Overview](#project-overview)
2. [Features](#features)
3. [Hardware Requirements](#hardware-requirements)
4. [System Design](#system-design)
5. [Code](#code)

---

## Project Overview

Water leaks, if unnoticed, can lead to significant damage in homes, especially in vulnerable areas like basements, kitchens, and bathrooms. This project aims to minimize such risks by providing immediate alerts when water is detected. The system uses a water sensor for detection and triggers both visual (LEDs) and auditory (buzzer) alarms, as well as a status display on an LCD screen.

Key features include:
- Immediate response to leaks.
- Clear alerts through sound, lights, and LCD notifications.
- Easy-to-reset functionality for reuse.

---

## Features

- **Real-time Detection**: Detects even small amounts of water using a calibrated water sensor.
- **Visual and Audio Alerts**: Activates LEDs and a buzzer when a leak is detected.
- **LCD Display**: Provides status updates such as "No Leak," "LEAK DETECTED," and "Alarm Stopped."
- **Two-Arduino System**: One Arduino for detection and another for alert management.
- **User-friendly**: Stop the alarm easily using a button.
- **Reliable Communication**: Serial communication ensures precise signals between Arduinos.

---

## Hardware Requirements

To build the Water Leak Detector, the following components are required:

- 2 Arduino boards
- 1 Water sensor
- 2 LEDs (Red)
- 1 Buzzer
- 1 16x2 LCD Display
- 1 Button
- 1 10k Ohm potentiometer
- Breadboard and wires
- 3x 220 Ohm resistors

---

## System Design

### Arduino Roles:
1. **Detection Arduino**:
   - Monitors the water sensor.
   - Sends signals (`'L'` for leak, `'N'` for no leak) to the Alert Arduino via serial communication.

2. **Alert Arduino**:
   - Activates LEDs, buzzer, and updates the LCD display upon receiving a leak signal.
   - Stops alarms when the button is pressed.

### Communication:
- **Serial Communication** ensures synchronized operation between the Arduinos.

### Inputs and Outputs:
- **Inputs**:
  - Water sensor (analog signal).
  - Button to stop the alarm.
- **Outputs**:
  - LEDs for visual alerts.
  - Buzzer for auditory alerts.
  - LCD for detailed status updates.

---


---

## Code

The code is divided into two sections:
- **Detection Arduino Code**: Monitors water levels and communicates leak status.
- **Alert Arduino Code**: Activates alerts and handles user interaction.

The full code is available in the repository under the `code/` folder:
- [Sensor Arduino Code](./code/sensor-arduino.ino)
- [Alert Arduino Code](./code/alert-arduino.ino)

---


![image](https://github.com/user-attachments/assets/ecd920e6-7ed6-4b6c-85ab-da0450bfe73f)
