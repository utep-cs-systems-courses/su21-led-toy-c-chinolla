#include <msp430.h>
#include "libTimer.h"
#include "buzzer.h"

static short E4 = 303;
static short C4 = 382;
static short G = 255;
static short G4 = 510;


void buzzer_init()
{
    /* 
       Direct timer A output "TA0.1" to P2.6.  
        According to table 21 from data sheet:
          P2SEL2.6, P2SEL2.7, anmd P2SEL.7 must be zero
          P2SEL.6 must be 1
        Also: P2.6 direction must be output
    */
    timerAUpmode();		/* used to drive speaker */
    P2SEL2 &= ~(BIT6 | BIT7);
    P2SEL &= ~BIT7; 
    P2SEL |= BIT6;
    P2DIR = BIT6;		/* enable output to speaker (P2.6) */
}

void buzzer_set_period(short cycles) /* buzzer clock = 2MHz.  (period of 1k results in 2kHz tone) */
{
  CCR0 = cycles; 
  CCR1 = cycles >> 1;		/* one half cycle */
}


void song(){
  char song[] = "ECG";
  int i = 0;
  char ele = song[i];
  switch(ele){
  case 'E':
    buzzer_set_period(100);
    break;
  case 'C':
    buzzer_set_period(1000);
    break;
  case 'G':
    buzzer_set_period(3000);
    break;
  }
  if (i == sizeof(song) - 1){
    i = 0;
  }
  else
    i++;
}

    
    
  

