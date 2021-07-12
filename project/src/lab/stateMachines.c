#include <msp430.h>
#include "stateMachines.h"
#include "led.h"
#include "switches.h"
#include "buzzer.h"

static char rswitch = 0;
static char gswitch = 0;


void toggle_red(){
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

void toggle_green(){
  green_on = !green_on;
}
void turn_on_red(){
  red_on = 1;
  led_changed = 1;
  led_update();
}

void turn_off_red(){
  red_on = 0;
  led_changed = 1;
  led_update();
}

void red_high(){
  switch(rswitch){
  case 0:
    turn_on_red();
    rswitch = 1;
    break;
  case 1:
    turn_on_red();
    rswitch = 2;
    break;
  case 2:
    turn_off_red();
    rswitch = 0;
    break;
  }
}
void red_med(){
  switch(rswitch){
  case 0:
    turn_on_red();
    rswitch = 1;
    break;
  case 1:
    turn_off_red();
    rswitch = 0;
    break;
  }
}
    

void red_low(){
  switch(rswitch){
  case 0:
    turn_on_red();
    rswitch = 1;
    break;
  case 1:
    turn_off_red();
    rswitch = 2;
    break;
  case 2:
    turn_off_red();
    rswitch = 0;
    break;
  }
}

void red_level(int level){
  switch(level){
  case 0:
    red_high();
    break;
  case 1:
    red_med();
    break;
  case 2:
    red_low();
    break;
  case 3:
    turn_off_red();
    level = 0;
    break;
  }
}



void state_advance(blink_count){
  switch(button_state){
  case 1:
    turn_on_red();
    break;
  case 2:
    turn_off_red();
    buzzer_set_period(0);
    break;
  case 3:
    red_level(blink_count);
    break;
  case 4:
    buzzer_set_period(300);
    break;
  }
}

void green_state_advance(){
  toggle_green();
  led_changed = 1;
  led_update();
}


void button_led(){
  if(s1){
    turn_on_red();
  }
  if(s2){
    turn_off_red();
  }
}
