// Defining Pins for the STM32F103C8T6
#define LEDPin 1 // Define the Relay Module pin as PB12

char incomingMessage[100]; // Array to store incoming SMS
bool sentMessage = false;  // Flag to control SMS sending

void setup()
{
  pinMode(LEDPin, OUTPUT); // Set the LED pin as an output
  
  Serial1.begin(115200);  // Use Serial1 for STM32, adjust the baud rate as needed
  Serial.begin(115200);   // Initialize the Arduino serial port
  delay(1000);            // Wait for the GSM module to start

  // Initialize the GSM module
  Serial1.println("AT");
  delay(1000);
  Serial1.println("AT+CMGF=1"); // Set SMS mode to text
  delay(1000);
  Serial1.println("AT+CNMI=2,2,0,0,0"); // Enable SMS notifications
  delay(1000);
}

void loop()
{
  // Check for incoming SMS
  if (Serial1.available()) {
    char c = Serial1.read();
    if (c == '\n') {
      // Check the received message
      if (strstr(incomingMessage, "ledon") != NULL) {
        digitalWrite(LEDPin, HIGH);
        delay(1000);
        
        if (!sentMessage) {
          char mobileNumber[] = "+254797957065"; // Enter the Mobile Number you want to send to
          char ATcommand[80];
          uint8_t buffer[30] = {0};
          uint8_t ATisOK = 0;

          while (!ATisOK) {
            sprintf(ATcommand, "AT\r\n");
            Serial1.print(ATcommand);
            delay(1000);
            if (Serial1.find("OK")) {
              ATisOK = 1;
            }
            delay(1000);
          }

          sprintf(ATcommand, "AT+CMGF=1\r\n");
          Serial1.print(ATcommand);
          delay(100);
          Serial1.readBytes(buffer, sizeof(buffer));
          delay(1000);
          memset(buffer, 0, sizeof(buffer));

          sprintf(ATcommand, "AT+CMGS=\"%s\"\r\n", mobileNumber);
          Serial1.print(ATcommand);
          delay(100);
          sprintf(ATcommand, "LED is Switched On%c", 0x1a);
          Serial1.print(ATcommand);
          delay(4000);

          sentMessage = true; // Set the flag to true to indicate that the message has been sent
        }
      } else if (strstr(incomingMessage, "ledoff") != NULL) {
        digitalWrite(LEDPin, LOW);
        delay(1000);
        
        if (!sentMessage) {
          char mobileNumber[] = "+254797957065"; // Enter the Mobile Number you want to send to
          char ATcommand[80];
          uint8_t buffer[30] = {0};
          uint8_t ATisOK = 0;

          while (!ATisOK) {
            sprintf(ATcommand, "AT\r\n");
            Serial1.print(ATcommand);
            delay(1000);
            if (Serial1.find("OK")) {
              ATisOK = 1;
            }
            delay(1000);
          }

          sprintf(ATcommand, "AT+CMGF=1\r\n");
          Serial1.print(ATcommand);
          delay(100);
          Serial1.readBytes(buffer, sizeof(buffer));
          delay(1000);
          memset(buffer, 0, sizeof(buffer));

          sprintf(ATcommand, "AT+CMGS=\"%s\"\r\n", mobileNumber);
          Serial1.print(ATcommand);
          delay(100);
          sprintf(ATcommand, "LED is Switched Off%c", 0x1a);
          Serial1.print(ATcommand);
          delay(4000);

          sentMessage = true; // Set the flag to true to indicate that the message has been sent
        }
      }
      // Clear the message buffer
      memset(incomingMessage, 0, sizeof(incomingMessage));
    } else {
      // Append the received character to the message buffer
      strncat(incomingMessage, &c, 1);
    }
  }
}
