#include <msp430.h>
#include "stateMachines.h"
#include "led.h"

static char blink_count = 0;
char time = 0;


void
__interrupt_vec(WDT_VECTOR) WDT(){	/* 250 interrupts/sec */
 
  if(time == 25){
    blink_count++;
    time = 0;
  }
  
  if (blink_count == 1) {
    state_advance();
    blink_count = 0;
  }
  else if(blink_count == 0){
    state_advance();

  }
  time++;
  blink_count++;
}