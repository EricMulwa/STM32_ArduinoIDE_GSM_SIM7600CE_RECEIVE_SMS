# STM32_ArduinoIDE_GSM_SIM7600CE_SEND_RECEIVE_SMS

For Libraries and IDE Initializations, check my previous repository on "STM32_GSM_SEND_SMS with GSM SIM7600CE"

This Arduino sketch allows you to control a relay module using an STM32F103C8T6 microcontroller and a 4G GSM SIM7600CE module. 
It's designed for remote control of a connected device by sending SMS commands. The code initializes the GSM module, listens for incoming SMS messages, and activates the relay based on specific commands.
## Features
- Switch the relay on (LED on) with the "ledon" SMS command.
- Switch the relay off (LED off) with the "ledoff" SMS command.
- Sends a confirmation SMS after the relay status change.
## Hardware Requirements
- STM32F103C8T6 microcontroller.
- GSM SIM7600CE module for SMS communication.
- Relay module connected to the specified pin (LEDPin).

## Getting Started
1. Define the pin for the relay module in the code.
2. Configure the GSM module parameters.
3. Upload the code to the STM32F103C8T6 microcontroller.
4. Insert a SIM card and power up the system.
5. Send SMS commands to control the relay (e.g., "ledon" or "ledoff").
## Usage
- When a valid SMS command is received, the relay will be toggled accordingly, and a confirmation SMS will be sent to the specified mobile number.

Please note that this code is a basic example and can be expanded to support more commands or additional functionalities as per your project requirements.
## Author
ERIC MULWA BSc Eng 


# Before Using the Program

Before you can use the program, you need to install the STM32Duino library. Follow these steps to set up the environment:

1. **Install the STM32Duino Library:**

   To use this program, you'll need to install the STM32Duino library. You can do this by adding a custom URL to your Arduino IDE's Boards Manager. Follow these steps:

   - Copy the following link:
     ```
     http://dan.drown.org/stm32duino/package_STM32duino_index.json
     ```
   - Open the Arduino IDE.
   - Go to `File > Preferences`.
   - In the "Additional Boards Manager URLs" field, paste the copied link.
   - Click "OK" to save the changes.

2. **Install STM32Duino Packages:**

   - Open the Arduino IDE.
   - Go to `Tools > Board > Boards Manager`.
   - In the Boards Manager, search for "STM32" and install the following packages:
     - "STM32F1xx"
     - STM32F4xx


3. **Select Your Board Variant:**
     - "STM32 72MHz CPU Speed"
     - "STM32 COM Port 3"
     - "STM32 ST-Link Upload Method"
  I used the STM32F103CB 128K Flash Variant, COM Port 3, 72MHz CPU Speed and ST-Link Upload Method.

Depending on your specific hardware configuration, you may need to select the appropriate board variant. For example, you can choose the "STM32F103CB 128K Flash Variant" as the target board.

Now, your environment is set up to use the program with the STM32Duino library and the necessary packages. You can upload the code to your STM32F103C8T6 microcontroller and start using the SMS sending functionality.

## Author
Eric Mulwa Eng BSc 

