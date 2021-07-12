#include <msp430.h>
#include "stateMachines.h"
#include "switches.h"

static char blink_count = 0;
char time = 0;


void
__interrupt_vec(WDT_VECTOR) WDT(){	/* 250 interrupts/sec */
 
  if(blink_count <= 250){
    state_advance();
    blink_count = 0;
  }
  else if(blink_count == 250){
    turn_off_red();
    blink_count++;
  }
}
