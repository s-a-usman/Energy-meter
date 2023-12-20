### ESP32 Blynk IoT Energy Meter

#### Overview

This repository contains Arduino code for an IoT-based energy meter developed with ESP32 and Blynk IoT platform integration. The project enables real-time monitoring and visualization of voltage (Vrms), current (Irms), apparent power, and cumulative energy consumption (kWh) on a Liquid Crystal Display (LCD) and the Blynk mobile app interface. Leveraging the EmonLib library, it accurately measures voltage and current, calculates energy usage, and communicates data to the Blynk app for remote access and visualization. Users can configure Wi-Fi credentials, Blynk authentication tokens, and specific device settings in the code to adapt it to their network and hardware setup. This repository serves as a comprehensive reference implementation for an IoT-based energy monitoring system using ESP32, Blynk, and an LCD display.

#### Key Features

- Real-time monitoring of Vrms, Irms, apparent power, and kWh consumption.
- Integration with Blynk IoT platform for remote access and visualization.
- Use of EmonLib library for accurate voltage and current measurements.
- Customizable configuration for Wi-Fi, Blynk authentication, and device details.

#### Getting Started

1. Clone the repository: `git clone https://github.com/s-a-usman/Energy-meter.git`
2. Configure Wi-Fi credentials, Blynk authentication token, and device details in the code.
3. Upload the Arduino code to your ESP32 microcontroller.
4. Open the Blynk mobile app, configure widgets, and link with your ESP32 device.

#### Acknowledgments

Special thanks to the open-source community for inspiration and resources.

---
