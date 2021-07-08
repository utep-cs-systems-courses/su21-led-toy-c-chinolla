#include <msp430.h>
#include "stateMachines.h"
#include "led.h"

static char rswitch = 0;
static char gswitch = 0;

char toggle_red(){
  switch(rswitch){
  case 0:
    red_on = 1;
    rswitch = 1;
    break;
  case 1:
    red_on = 0;
    rswitch = 0;
    break;
  }
}

char toggle_green(){
  green_on =  !green_on;
}

void state_advance(){
  toggle_red();
  led_changed = 1;
  led_update();
}

char green_state_advance(){
  toggle_green();
  led_changed = 1;
  led_update();
}
