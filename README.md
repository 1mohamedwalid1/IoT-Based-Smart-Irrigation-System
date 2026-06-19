# 🌱 IoT-Based Smart Irrigation System

An automated, WiFi-connected irrigation system built on the **NodeMCU ESP8266**, integrated with **Blynk IoT** for real-time remote monitoring and control. The system continuously reads soil moisture, temperature, and humidity, then automatically activates a water pump when the soil becomes too dry — no manual intervention required.

## How It Works

1. The soil moisture sensor measures the water content in the soil.
2. The DHT sensor measures ambient temperature and humidity.
3. The NodeMCU ESP8266 reads both sensors and evaluates soil moisture against a threshold (30%).
4. If the soil is too dry, the ESP8266 triggers the relay module, which switches the water pump ON. Once moisture is sufficient, the pump turns OFF.
5. All sensor data (temperature, humidity, soil moisture) is pushed to the **Blynk dashboard** for live remote monitoring.

## Hardware Components


NodeMCU ESP8266: Main microcontroller, WiFi connectivity
DHT11 Sensor: Measures temperature and humidity 
Soil Moisture Sensor: Measures water content in soil 
Relay Module: Interfaces between the microcontroller and the pump
Water Pump: Delivers water to the soil 

## Circuit Overview

Soil Sensor (AO) → ESP8266 analog pin (A0)
DHT Sensor → ESP8266 digital pin (D1 / GPIO5)
Relay Module (IN)→ ESP8266 digital pin (D0 / GPIO16)
Relay Module → switches 12V power to the Pump (N.O. contact)

A full hand-drawn wiring diagram is included in the repository (`circuit_diagram.jpeg`).

## Software / Platform

- **Arduino IDE** (C/C++)
- **Blynk IoT Platform** for dashboard visualization and remote monitoring
- Libraries used: `DHT11`, `ESP8266WiFi`, `BlynkSimpleEsp8266`

## Blynk Virtual Pins

| V1 | Humidity |
| V2 | Temperature |
| V3 | Soil Moisture (%) |

## Features

- ✅ Fully automated irrigation based on real soil moisture readings
- ✅ Live remote monitoring via the Blynk mobile app
- ✅ Simple, low-cost hardware (sourced from the Egyptian market)

## Future Improvements

- Replace blocking `delay()` calls with non-blocking `millis()` timing
- Add configurable moisture threshold via the Blynk app
- Add scheduling/automation rules (e.g., no irrigation at night)

