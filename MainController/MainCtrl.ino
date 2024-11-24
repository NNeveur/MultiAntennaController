
#include "Arduino.h"
#include <EEPROM.h>
#include "math.h"
#include "EasyNextionLibrary.h" // https://github.com/Seithan/EasyNextionLibrary
//#include <FreqCount.h>
#include "MainCtrl.h"


EasyNex myNex(UART_DISP);

struct antenna
{
  unsigned active : 1;
  char etiquette[20];
  unsigned band1 : 1;
  unsigned band2 : 1;
  unsigned band3 : 1;
  unsigned band4 : 1;
  unsigned band5 : 1;
  unsigned band6 : 1;
  unsigned band7 : 1;
  unsigned band8 : 1;
  unsigned band9 : 1;
  unsigned band10 : 1;
  unsigned band11 : 1;
  unsigned LoopAnt : 1;
  unsigned VLAnt : 1;
  unsigned ATASAnt : 1;
};

antenna ant1;
antenna ant2;
antenna ant3;
antenna ant4;
antenna ant5;
antenna ant6;
antenna ant7;
antenna ant8;

struct mode
{
  uint8_t freqsource;
  uint8_t selector;
} OpMode;

// Radio selection, where:
// (selection can be changed using the Menu function)
// 0  = ICOM CI-V Auto
// 1  = ICOM CI-V Poll
// 2  = Kenwood TS-440
// 3 =  Kenwood TS-870
// 4  = Kenwood TS-480/TS-590/TS-2000
// 5  = Yaesu FT-100
// 6  = Yaesu FT-7X7 (747...)
// 7  = Yaesu FT-8x7 (817,847,857,897)
// 8  = Yaesu FT-920
// 9  = Yaesu FT-990
// 10 = Yaesu FT-1000MP
// 11 = Yaesu FT-1000MP Mk-V
// 12 = Yaesu FT-450/950/1200/2000/3000/5000
// 13 = Elecraft K3/KX3 Auto
// 14 = Elecraft K3/KX3 Poll
// 15 = TenTec binary mode
// 16 = TenTec ascii mode

struct radio
{
  uint8_t model;
  uint16_t speed;
  uint8_t port;             // 0 = TTL polarity, 1 = Reverse polarity Serial (if RS232 without MAX232)
  uint8_t param;             // SERIAL_8N1
  boolean passthrough;      // Pass all data from USB (computer) to serial (radio) and vice versa
  uint16_t pollRate; 
  uint8_t  ICOM_address;    // ICOM CI-V Address, only relevant for ICOM transceivers
  uint8_t  tx_pwrlevel; 
} RadioParam;

struct  {
          int32_t  Frq;                  // Frequency information in Hz        
          int32_t  Pos;                  // Position Information, referenced at 1000000
         } var_track;             // 64 bits, 8 bytes

struct  {
          int8_t  units;                  // Frequency information in Hz        
          int8_t  MotorN;                  // Frequency information in Hz        
          int8_t  encoderN;                  // Frequency information in Hz        
          int16_t pulseround;                  // Position Information, referenced at 1000000
          int16_t unitsround;                  // Position Information, referenced at 1000000
          int16_t motorspeed;                  // Position Information, referenced at 1000000
          int32_t maxlength;                  // Position Information, referenced at 1000000
         } vl_param;             // 104 bits, 13 bytes

uint8_t last_display_ant = 0;
uint8_t last_ant_relay = 0;
uint8_t last_display_mant = 0;

uint8_t current_ant = 1;
uint8_t current_band = 1;
uint8_t last_ant = 0;

uint8_t ant_bank = 0;

uint8_t CheckInit = 0;

void setup() {
  // put your setup code here, to run once:
myNex.begin(Dispbaud); // start Nextion Display
myNex.writeStr("page 0");
delay(2000);
myNex.writeStr("page MenuSetup");

Serial.begin(9600);
UART_RS422.begin(RSbaud);

EEPROM.get(0, CheckInit);
if (CheckInit != 99){
  CheckInit=99;
  EEPROM.put(0, CheckInit);
  saveEEPROM();
} else loadEEPROM();

UART_CAT.begin(CATbaud);

set_ant(current_ant);
//Serial.println(sizeof(ant1));
//Serial.println(sizeof(ant2));
//Serial.println(sizeof(ant3));
//Serial.println(sizeof(ant4));
//Serial.println(sizeof(ant5));
//Serial.println(sizeof(ant6));
//Serial.println(sizeof(ant7));
//Serial.println(sizeof(ant8));

}

void loop() {
  // put your main code here, to run repeatedly:
 myNex.NextionListen();
}
