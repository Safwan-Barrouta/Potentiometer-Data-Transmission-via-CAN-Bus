#include <SPI.h>          // SPI library for CAN module communication
#include <mcp2515.h>      // MCP2515 CAN controller library

struct can_frame canMessage;  // CAN message structure
MCP2515 mcp2515(10);         // Initialize MCP2515 with CS pin 10

void setup() {
  Serial.begin(9600);     // Start serial communication at 9600 baud
  
  // Initialize CAN controller
  mcp2515.reset();                     // Reset CAN controller
  mcp2515.setBitrate(CAN_125KBPS);     // Set CAN bus speed to 125kbps
  mcp2515.setNormalMode();             // Set to normal operation mode
}

void loop() {
  // Check if a CAN message is received
  if (mcp2515.readMessage(&canMessage) == MCP2515::ERROR_OK) {
    // Filter for our specific message ID (0x001)
    if (canMessage.can_id == 0x001) { 
      // Reconstruct the 16-bit value from two 8-bit bytes
      int potValue = word(canMessage.data[0], canMessage.data[1]); 
      
      // Print received value to serial monitor
      Serial.println("Potentiometer Value: " + String(potValue)); 
    }
  }
}