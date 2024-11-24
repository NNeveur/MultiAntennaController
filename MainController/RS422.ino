//
char rs422_incoming_command_string[50];			                           // Input from USB Serial

void rs422_parse_incoming(void)
{
  uint8_t x;
  char *pEnd;
  int32_t  frq_in;
  #if PSWR_AUTOTUNE
  uint16_t inp_val;
  double inp_double;
  #endif

  if (!strcasecmp("frqget",rs422_incoming_command_string))	           // Retrieve calibration values
  {
    Serial.print(running[ant].Frq);
  }
  
  else if (!strncasecmp("frqset",rs422_incoming_command_string,6))     // Write new calibration values
  {
    frq_in = strtol(rs422_incoming_command_string+6,&pEnd,10);
    antenna_select(frq_in);      // Antenna switchover, if frequency applies to the other antenna  
    running[ant].Frq = frq_in;
    radio.timer = true;	         // Indicate that we are receiving frq data from Radio
    radio.online = true;
  }
  
}

void rs422_read_and_parse(void)
{
  static uint8_t a;                     // Indicates number of chars received in an incoming command
  static bool Incoming;
  uint8_t ReceivedChar;
  uint8_t waiting;                      // Number of chars waiting in receive buffer

  waiting = UART_RS422.available();         // Find out how many characters are waiting to be read.

  // CAT Passthrough mode. Pass everything from USB (computer) to serial (radio)
  // Only do this if SWR tune is not in progress 
 
    // Scan for a command attention symbol -> '$'
    if (waiting && !Incoming)
    {
      ReceivedChar = UART_RS422.read();
      // A valid incoming message starts with an "attention" symbol = '$'.
      // in other words, any random garbage received on USB port is ignored.
      if (ReceivedChar == '$')          // Start command symbol was received,
      {                                 // we can begin processing input command
        Incoming = true;
        a = 0;
        waiting--;
      }
     }	
    // Input command is on its way.  One or more characters are waiting to be read
    // and Incoming flag has been set. Read any available bytes from the USB OUT endpoint
    while (waiting && Incoming)
    {
      ReceivedChar = UART_RS422.read();
      waiting--;
      if (a == sizeof(rs422_incoming_command_string)-1)  // Line is too long, discard input
      {
        Incoming = false;
        a = 0;
      }
      // Check for End of line
      else if ((ReceivedChar=='\r') || (ReceivedChar=='\n') || (ReceivedChar==';'))
      {
        rs422_incoming_command_string[a] = 0; // Terminate line
        rs422_parse_incoming();           // Parse the command
        Incoming = false;
        a = 0;
      }
      else                              // Receive message, char by char
      {
        rs422_incoming_command_string[a] = ReceivedChar;
      }
      a++;                                         // String length count++
    }
  }
}
