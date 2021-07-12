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
    red_level(0);
  }
  else if(blink_count == 2){
    
    red_level(1);
  }
  else if(blink_count == 3){
    red_level(2);
    
  }
  else{
    red_level(3);
    blink_count = 0;
  }

  
 
  time++;
  
}
