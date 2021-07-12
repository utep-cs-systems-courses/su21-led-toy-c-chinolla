#include <msp430.h>
#include "stateMachines.h"
#include "switches.h"

static char blink_count = 0;
char time = 0;

void
__interrupt_vec(WDT_VECTOR) WDT(){	/* 250 interrupts/sec */
 
  if(time < 250){
    state_advance(blink_count);
    time++;
  }
  else if(time == 250){
    blink_count++;
    if(blink_count > 3)
      blink_count = 0;
    time = 0;
  }
}
