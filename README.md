# ESP32 Forest Monitoring System

IoT-based forest monitoring system designed to collect environmental data and support early wildfire detection using ESP32, environmental sensors, and long-range communications.

## Overview

This project was developed as part of the Telecommunications Engineering program at the University of Concepción.

The system was designed to monitor environmental variables such as temperature, humidity, air quality, and motion using an ESP32-based sensing node. The collected information is transmitted to a central monitoring system for analysis and visualization.

The project includes hardware design, sensor integration, communication architecture, firmware logic, data processing, and system validation.

## Technologies

- ESP32
- BME688 environmental sensor
- BMI270 inertial sensor
- LoRa / LoRaWAN
- MQTT
- HTTP
- I2C / SPI
- Embedded systems
- Environmental sensing
- IoT architecture
- Data acquisition and processing

## System Architecture

The system is composed of distributed sensing nodes and a central monitoring station.

Each sensing node includes:

- ESP32 microcontroller
- BME688 sensor for temperature, humidity and air quality
- BMI270 inertial sensor
- Battery-powered operation
- Long-range wireless communication
- Data processing and transmission logic

Sensor data is sent to a monitoring station where it can be stored, analyzed and used to generate alerts when abnormal environmental conditions are detected.

## Main Features

- Real-time environmental monitoring
- Temperature and humidity acquisition
- Air quality monitoring
- Motion and vibration detection
- Wireless data transmission
- Data filtering and processing
- Alert generation
- Modular and scalable IoT architecture

## Communications

The project considered different communication technologies for data transmission:

- **LoRaWAN** for long-range, low-power communication
- **MQTT** for lightweight IoT messaging
- **HTTP** for integration with monitoring and storage platforms

## Hardware Design

The project included the design of the electronic architecture around the ESP32 and environmental sensors.

The hardware design considered:

- Sensor interfaces
- Power supply
- Battery operation
- ESP32 connectivity
- PCB architecture
- Environmental protection and enclosure considerations

## Data Processing

The system was designed to process sensor data before transmission, including:

- Periodic data acquisition
- Data filtering
- Statistical analysis
- Detection of abnormal environmental conditions
- Generation of alerts based on predefined thresholds

The architecture was also designed to allow future integration of machine learning models for wildfire risk prediction.

## Testing

The project considered several validation stages:

- Unit testing
- Sensor testing
- Communication testing
- Integration testing
- System testing
- Performance testing

The objective was to verify correct sensor operation, data transmission stability and compatibility between system components.

## Project Context

Academic engineering project developed as part of the Telecommunications Engineering curriculum at the University of Concepción.

The project focused on the integration of telecommunications, embedded systems, IoT communications, environmental sensing and system design.

## Authors

Gabriel Gutiérrez Leal  
Telecommunications Engineering  
University of Concepción
