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
#define VL_EXP 	    "$VLEXP"	  // wire expand + speed
#define VL_RET	    "$VLRET"	  // wire retract + speed
#define VL_EXPP     "$VLEXPP"	  // wire expand + pulse #
#define VL_RETP	    "$VLRETP"	  // wire retract + pulse #
#define VL_STOP     "$VLST"		  // full stop
#define VL_PULSE_FB	"$VLPFB"		// set pulse number feedback + pulse #
#define VL_PULSE    "$VLP"		  // module command response every x pulse
#define VL_OK		    "$VLOK"		  // module command response

//
// macros VL man stepr antenna related
#define VL_PULSE_INCH	20		// encoder pulses per inch of wire
#define LAMDA4(f) ((5616/f)/2)	// freq mhz to 1/4 wave inchs
#define NPULSE(f) (((5616/f)/2)*VL_PULSE_INCH) 	// freq mhz to 1/4 wave encoder pulses
//
// ATAS Ctrl Module Commands
# define ATAS_UP 	"$ATASUP"	// antenna move up
# define ATAS_DOWN 	"$ATASDW"	// antenna move down
# define ATAS_STOP 	"$ATASST"	// full stop 
# define ATAS_OK	"$ATASOK"	// module command response
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
#define UART_RS485 Serial2
uint16_t RSbaud = 125000;
#define RS_En 6
#define UART_CAT Serial3
uint16_t CATbaud = 9600;

#define LoopTag "Mag Loop Ctrl"
#define VLTag "VariLength Ctrl"
#define ATASTag "Yeasu ATAS Ctrl"
#define InacTag "Inactive"
