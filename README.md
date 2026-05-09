# Autonomous-Car
The car navigates its environment independently by continuously scanning for obstacles and making real-time steering decisions — no human input required during operation.
# 🚗 Autonomous RC Car
### Embedded Systems Graduation Project 

> A fully autonomous RC vehicle prototype that detects and avoids obstacles in real time — no human control needed during operation.

---

## 📌 Overview

This project is an autonomous ground vehicle built from scratch as a graduation project. The car uses **ultrasonic sensors** to continuously scan its surroundings while moving, and makes instant steering decisions to avoid obstacles — fully on its own.

The control logic is written in **C** , which splits the car's brain into parallel tasks:
- One task reads sensor data
- One task processes the decision logic
- One task controls the motors

This separation ensures the car reacts **fast and reliably** without any task blocking another.

---

## ⚙️ How It Works

1. **Ultrasonic sensors** emit sound waves and measure how long they take to bounce back from objects
2. It runs detection, decision, and motor control tasks simultaneously
3. If an obstacle is detected within a threshold distance, the car **automatically steers away**
4. Once the path is clear, it **resumes forward motion**

---

## 🛠️ Built With

- **Language:** C
- **Sensors:** Ultrasonic sensors for obstacle detection
- **Hardware:** RC car chassis, microcontroller, motor driver module

---

## 🎯 Key Highlights

- ✅ Fully autonomous — zero manual input during operation
- ✅ Real-time response using RTOS multitasking
- ✅ Reliable obstacle avoidance at varying distances
- ✅ Clean modular code structure (sensing / logic / actuation)

---

