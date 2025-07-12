# Potentiometer Data Transmission via CAN Bus
## Description 
This project demonstrates CAN bus communication between two Arduino Uno boards, transmitting real-time potentiometer data using MCP2515 modules.
real-time potentiometer data using MCP2515 modules.
## Hardware Requirements
- 2 × Arduino Uno  
- 2 × MCP2515 CAN Module  
- 1× Potentiometer (10kΩ) 
- Jumper wires
## Wiring
1.Connect the MCP2515 modules to both Arduinos:
| MCP2515 | Arduino Uno |
|---------|-------------|
| VCC     | 5V          |
| GND     | GND         |
| CS      | D10         |
| SO      | D12 (MISO)  |
| SI      | D11 (MOSI)  |
| SCK     | D13 (SCK)   |
| INT     | Not connected (or D2)|

2.Connect the potentiometer to the sender Arduino:
| Potentiometer | Arduino Uno |
|---------|-------------|
| VCC     | 5V          |
| GND     | GND         |
| Signal    | A0 |

3.Connect the CAN bus lines:
| MCP2515 Module 1 | MCP2515 Module 2 |
|---------|-------------|
| CAN High (H) | CAN High (H) |
| CAN Low (L) | CAN Low (L) |
## Software Requirements
- Required library: [`mcp2515`] (https://github.com/autowp/arduino-mcp2515).
- Arduino IDE configured with the correct board (`Arduino Uno`) and port.
  
## Usage
1.Upload `Sender/Sender.ino` to the Arduino with a potentiometer.

2.Upload `Receiver/Receiver.ino` to the other Arduino.

3.The sender will transmit potentiometer values via the CAN bus.

4.The receiver will display received values on the Serial Monitor.



