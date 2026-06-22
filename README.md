# IOT-based-BMS-for-remote-battery-health-monitoring-and-prevention
An IoT-based Battery Management System for remote health monitoring and prevention is designed to continuously track battery performance, predict failures, and extend battery life using sensor data, cloud connectivity, and machine learning models. It enables proactive maintenance, reduces downtime, and ensures safety in energy storage .
# IoT-Based BMS for Remote Battery Health Monitoring and Optimization

This repository contains the complete implementation of an IoT-enabled Battery Management System (BMS) that integrates real-time hardware telemetry collection with machine learning to monitor and optimize battery health remotely. The architecture bridges an **ESP32 edge node** with an interactive **Streamlit web application** running a **Random Forest Regressor** to predict battery longevity and safety metrics.

🔗 **Published Research Paper:** [IJISRT Journal Link](https://www.ijisrt.com/iotbased-bms-for-remote-battery-health-monitoring-and-optimization)

---

## 📌 Abstract
This project presents the development of an IoT-based Battery Management System (BMS) utilizing the Random Forest Regressor machine learning model for remote battery health monitoring and optimization.The system integrates IoT-enabled sensors to collect real-time battery parameters such as voltage, current, and temperature.This data is transmitted through secure IoT gateways to a cloud platform for processing.The Random Forest Regressor is employed to predict critical battery metrics, including capacity degradation and remaining useful life (RUL).The system enhances predictive accuracy and enables informed decision-making for optimized battery usage, thereby improving efficiency and longevity.

---

## 📊 System Architecture & Methodology

The project uses a multilayer End-Edge-Cloud architecture divided into local physical monitoring and cloud-based intelligence:

1. Data Collection (Edge Node):** An ESP32 microcontroller with built-in Wi-Fi reads physical parameters from the battery cells.
   - Voltage & Current:** Tracks real-time state of charge (SOC) and capacity degradation trends.
   -Temperature (DHT11):** Monitors for overheating conditions
   - Smoke/Gas Sensor (MQ135):** Added to detect gas outpourings or combustion signs before critical thermal runaway
2. Local Closed-Loop Optimization:** If the edge sensors detect severe over-temperature or gas thresholds, the ESP32 activates a localized Relay Module connected to a spray/cooling safety mechanism to isolate hazards instant
3. Cloud Analytics Pipeline:** Data is streamed securely to the Blynk IoT platform and the Streamlit interface.A cloud-hosted **Random Forest Regressor** processes these non-linear feature maps to predict State of Health (SOH) and Remaining Useful Life (RUL)


---

## 📁 Repository Directory Structure

Organize your files locally exactly like this before pushing to GitHub:

```text
├── app.py                      # Streamlit Python Interactive Web Dashboard
├── requirements.txt            # Python Dependency Frameworks
├── README.md                   # Project Documentation & Guide
├── firmware/
│   └── firmware.ino            # ESP32 Arduino C++ Code
└── images/
    ├── block_diagram.png        # System Block Diagram from Journal
    ├── hardware_setup.jpg       # Image of your actual physical hardware
    └── streamlit_output.png     # Screenshot of your local web interface
