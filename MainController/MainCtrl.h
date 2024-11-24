// AntSwitcher.h
//#include "Nextriger.ino"
//
// Ant Ctrl Module Commands
#define SW_ALL_OFF  "$SWOFFALL"	// all relays switch off
#define SW_ALL_ON 	"$SWONALL"	// all relays switch on
#define SW_ANT_OFF	"$SWOFFA"	  // relay switch off + relay #
#define SW_ANT_ON 	"$SWONA"	  // relay switch on + relay #
#define SW_OK		    "$SWOK"		  // module command response
//
//
// Loop Ctrl Module Commands
#define LOOP_INCR  	"$LPINC"	// stepper increment + resolution step
#define LOOP_DECR 	"$LPDEC"	// stepper decrement + resolution step
#define LOOP_MOVE 	"$LPMOV"	// stepper move
#define LOOP_OFF	  "$LPOFF"	// stepper power off
#define LOOP_ON		  "$LPON"		// stepper power on
#define LOOP_INIT	  "$LPINI"	// stepper initialisation
#define LOOP_OK		  "$LPOK"		// module command response
//
//
// VL Ctrl Module Commands
#define VL_EXPP     "$VLEXPP"	  // wire expand + pulse #
#define VL_RETP	    "$VLRETP"	  // wire retract + pulse #
#define VL_MOVEP    "$VLMOVEP"	// wire move to + position (in pulse)
#define VL_STOP     "$VLST"		  // full stop
#define VL_SETP     "$VLSETP"		// set position in pulse
#define VL_SETM     "$VLSETM"		// set number of motor 1 or 2
#define VL_POS      "$VLPOS"		// module command response position in pulse
#define VL_OK		    "$VLOK"		  // module command response
#define VL_READY    "$VLREADY"	// module command response READY

//
// macros VL antenna related
#define VL_PULSE_INCH	109		// encoder pulses per inch of wire
#define LAMDA4(f) ((5616/f)/2)	// freq mhz to 1/4 wave inchs
#define NPULSE(f) (((5616/f)/2)*VL_PULSE_INCH) 	// freq mhz to 1/4 wave encoder pulses
//
// ATAS Ctrl Module Commands
# define ATAS_UP  	"$ATASUP"	// antenna move up
# define ATAS_DOWN 	"$ATASDW"	// antenna move down
# define ATAS_STOP 	"$ATASST"	// full stop 
# define ATAS_OK	  "$ATASOK"	// module command response
//
//
//
// Bool stuff
#define WORKING    0 
#define DONE       1
#define SUCCESS    1
#define FAIL       2
#define NOPWR      3

//-----------------------------------------------------------------------------
// Soft Reset Teensy 3 style
#define RESTART_ADDR       0xE000ED0C
#define RESTART_VAL        0x5FA0004
#define SOFT_RESET()       ((*(volatile uint32_t *)RESTART_ADDR) = (RESTART_VAL))

//-----------------------------------------------------------------------------
// Macros
#ifndef SQR
#define SQR(x) ((x)*(x))
#endif
#ifndef ABS
#define ABS(x) ((x>0)?(x):(-x))
#endif

#define UART_DISP Serial1
#define Dispbaud 115200
#define UART_RS422 Serial2
uint16_t RSbaud = 19200;
#define UART_CAT Serial3
uint16_t CATbaud = 9600;

#define LoopTag "Mag Loop Ctrl"
#define VLTag "VariLength Ctrl"
#define ATASTag "Yeasu ATAS Ctrl"
#define InacTag "Inactive"

#define Encoder0 2
#define Encoder1 3
#define EncoderSW 4

uint8_t ModeCtrl = 0;   // 0=Main menu 1=Selector 2=LoopCtrl 3=VariCtrl 4=ATASCtrl
#define MainMenu 0
#define Selector 1
#define LoopCtrl 2
#define VariCtrl 3
#define ATASCtrl 4


