# Touchless Fan Control using Ultrasonic Sensor & Relay (Arduino)

This project demonstrates a contactless, gesture-based fan switch using an ultrasonic distance sensor, 
Arduino Uno, and a relay module. By simply waving a hand within a certain range (5–12 cm), the system toggles a fan ON or OFF, 
making it a smart and hygienic solution for homes, kitchens, labs, or workshops.

# Project Highlights
✅ Hygienic Control: No need to touch switches with wet or greasy hands—perfect for kitchen or lab use.
✅ Gesture Activated: Detects hand movement using ultrasonic sensing (HC-SR04).
✅ Relay Integration: Controls an actual AC fan or any other appliance via a relay module.
✅ Debounce Logic: Prevents accidental multiple toggles through smart timing control.
✅ Compact & Cost-Effective: Uses minimal components and fits into small spaces.

# How It Works
✅ The HC-SR04 ultrasonic sensor detects an object (your hand) within a 5–12 cm range.
✅ When a hand enters this zone (and was not already there), the system toggles the fan state (ON/OFF).
✅ A relay module is used to control a 220V AC fan (or other appliance).
✅ The system incorporates a 1.5-second debounce delay to avoid repeated toggles from lingering hand movement.

# Components Required
✅ Arduino Uno R3
✅ HC-SR04 Ultrasonic Sensor
✅ Relay Module (5V)
✅ Jumper Wires	As needed
✅ Breadboard (optional)	
✅ AC Fan (or bulb for test)	
✅ AC-DC Adapter 5v 3Amp
✅ Multimeter for testing (optional)	
