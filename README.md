# ESP32 MQTT Client

This project demonstrates how to use an ESP32 microcontroller to connect to a Wi-Fi network and communicate with an MQTT broker. It utilizes the `WiFi` and `PubSubClient` libraries to manage Wi-Fi connections and MQTT messaging.

## Features

- Connects to a Wi-Fi network using provided credentials.
- Connects to an MQTT broker.
- Subscribes to an MQTT topic and listens for incoming messages.
- Publishes a message to an MQTT topic upon connection.

## Prerequisites

Before running the code, ensure you have the following:

- An ESP32 microcontroller.
- The [Arduino IDE](https://www.arduino.cc/en/software) installed with ESP32 support.
- The `WiFi` and `PubSubClient` libraries installed in the Arduino IDE.

## Installation

1. **Set Up the Arduino IDE for ESP32**:
   - Follow the instructions on the [ESP32 Arduino GitHub page](https://github.com/espressif/arduino-esp32) to install the necessary board definitions.

2. **Install Required Libraries**:
   - Open the Arduino IDE and navigate to **Sketch > Include Library > Manage Libraries**.
   - Search for and install the `PubSubClient` library.

3. **Configure the Code**:
   - Open the provided code in the Arduino IDE.
   - Update the Wi-Fi credentials:
     ```cpp
     const char* ssid = "your_wifi_ssid";
     const char* password = "your_wifi_password";
     ```
   - Update the MQTT broker credentials:
     ```cpp
     IPAddress server(192, 168, 178, 30); // Replace with your broker's IP address
     ```

4. **Upload the Code**:
   - Connect your ESP32 to your computer.
   - Select the correct board and port in the Arduino IDE.
   - Upload the code to the ESP32.

## Code Overview

### Libraries

- `WiFi.h`: Manages the Wi-Fi connection.
- `PubSubClient.h`: Manages MQTT communication.

### GPIOs

- `LED`: GPIO 2 is used for an LED indicator.

### Functions

- `callback()`: Handles incoming MQTT messages.
- `startWifi()`: Connects the ESP32 to the Wi-Fi network.
- `connectBroker()`: Connects the ESP32 to the MQTT broker and subscribes to a topic.

### MQTT Topics

- **Publishing**: The ESP32 publishes a message to the `outTopic` topic upon connection.
- **Subscribing**: The ESP32 subscribes to the `test` topic and processes incoming messages via the `callback()` function.

## Usage

1. **Start**: After uploading the code, the ESP32 will connect to the specified Wi-Fi network.
2. **Connect**: It will then connect to the MQTT broker and publish a message to the `outTopic`.
3. **Subscribe**: The ESP32 will subscribe to the `test` topic and print incoming messages to the Serial Monitor.

## Troubleshooting

- **No Wi-Fi Connection**: Ensure that the Wi-Fi credentials are correct and that the ESP32 is within range of the network.
- **MQTT Connection Issues**: Verify that the MQTT broker's IP address and credentials are correct and that the broker is reachable.

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.


