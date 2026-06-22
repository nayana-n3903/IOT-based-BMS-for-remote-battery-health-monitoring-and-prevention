# IOT-based-BMS-for-remote-battery-health-monitoring-and-prevention
An IoT-based Battery Management System for remote health monitoring and prevention is designed to continuously track battery performance, predict failures, and extend battery life using sensor data, cloud connectivity, and machine learning models. It enables proactive maintenance, reduces downtime, and ensures safety in energy storage .
# IoT-Based BMS for Remote Battery Health Monitoring and Optimization

[span_0](start_span)This repository contains the complete implementation of an IoT-enabled Battery Management System (BMS) that integrates real-time hardware telemetry collection with machine learning to monitor and optimize battery health remotely[span_0](end_span). [span_1](start_span)[span_2](start_span)The architecture bridges an **ESP32 edge node** with an interactive **Streamlit web application** running a **Random Forest Regressor** to predict battery longevity and safety metrics[span_1](end_span)[span_2](end_span).

🔗 **Published Research Paper:** [IJISRT Journal Link](https://www.ijisrt.com/iotbased-bms-for-remote-battery-health-monitoring-and-optimization)

---

## 📌 Abstract
[span_3](start_span)This project presents the development of an IoT-based Battery Management System (BMS) utilizing the Random Forest Regressor machine learning model for remote battery health monitoring and optimization[span_3](end_span). [span_4](start_span)The system integrates IoT-enabled sensors to collect real-time battery parameters such as voltage, current, and temperature[span_4](end_span). [span_5](start_span)This data is transmitted through secure IoT gateways to a cloud platform for processing[span_5](end_span). [span_6](start_span)The Random Forest Regressor is employed to predict critical battery metrics, including capacity degradation and remaining useful life (RUL)[span_6](end_span). [span_7](start_span)The system enhances predictive accuracy and enables informed decision-making for optimized battery usage, thereby improving efficiency and longevity[span_7](end_span).

---

## 📊 System Architecture & Methodology

[span_8](start_span)The project uses a multilayer End-Edge-Cloud architecture divided into local physical monitoring and cloud-based intelligence[span_8](end_span):

1. **[span_9](start_span)[span_10](start_span)Data Collection (Edge Node):** An ESP32 microcontroller with built-in Wi-Fi reads physical parameters from the battery cells[span_9](end_span)[span_10](end_span).
   - **[span_11](start_span)[span_12](start_span)Voltage & Current:** Tracks real-time state of charge (SOC) and capacity degradation trends[span_11](end_span)[span_12](end_span).
   - **[span_13](start_span)[span_14](start_span)Temperature (DHT11):** Monitors for overheating conditions[span_13](end_span)[span_14](end_span).
   - **[span_15](start_span)Smoke/Gas Sensor (MQ135):** Added to detect gas outpourings or combustion signs before critical thermal runaway[span_15](end_span).
2. **[span_16](start_span)Local Closed-Loop Optimization:** If the edge sensors detect severe over-temperature or gas thresholds, the ESP32 activates a localized Relay Module connected to a spray/cooling safety mechanism to isolate hazards instantly[span_16](end_span).
3. **[span_17](start_span)[span_18](start_span)Cloud Analytics Pipeline:** Data is streamed securely to the Blynk IoT platform and the Streamlit interface[span_17](end_span)[span_18](end_span). [span_19](start_span)[span_20](start_span)A cloud-hosted **Random Forest Regressor** processes these non-linear feature maps to predict State of Health (SOH) and Remaining Useful Life (RUL)[span_19](end_span)[span_20](end_span).

<p align="center">
  <img src="images/block_diagram.png" alt="Proposed Block Diagram" width="70%"/>
</p>

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
