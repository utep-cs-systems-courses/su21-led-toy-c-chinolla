#include <msp430.h>
#include "stateMachines.h"
#include "led.h"

static char blink_count = 0;
char time = 0;


void
__interrupt_vec(WDT_VECTOR) WDT(){	/* 250 interrupts/sec */
 
  if(time == 250){
    blink_count++;
    time = 0;
  }
  
  if (blink_count == 1) {
    state_advance();
  }
  else if(blink_count == 2){
    
    green_state_advance();
  }
  else if(blink_count == 3){
    blink_count = 0;
  }

  
 
  time++;
  
}
