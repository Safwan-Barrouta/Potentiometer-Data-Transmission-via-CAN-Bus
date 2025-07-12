#include <SPI.h>          // SPI library for CAN module communication
#include <mcp2515.h>      // MCP2515 CAN controller library

struct can_frame canMessage;  // CAN message structure
MCP2515 mcp2515(10);         // Initialize MCP2515 with CS pin 10

void setup() {
  while (!Serial);        // Wait for serial port to connect (for debugging)
  Serial.begin(9600);     // Start serial communication at 9600 baud
  
  // Initialize CAN controller
  mcp2515.reset();                     // Reset CAN controller
  mcp2515.setBitrate(CAN_125KBPS);     // Set CAN bus speed to 125kbps
  mcp2515.setNormalMode();             // Set to normal operation mode
}

void loop() {
  // Read potentiometer value (0-1023)
  int potValue = analogRead(A5); 
  
  // Prepare CAN message
  canMessage.can_id  = 0x001;         // Set CAN message ID
  canMessage.can_dlc = 2;             // Set data length (2 bytes)
  canMessage.data[0] = highByte(potValue);  // Store high byte of potentiometer value
  canMessage.data[1] = lowByte(potValue);   // Store low byte of potentiometer value
  
  // Send CAN message
  mcp2515.sendMessage(&canMessage); 
  
  // Print value to serial monitor for debugging
  Serial.println(potValue);
  
  delay(100);  // Short delay to prevent flooding the CAN bus
}