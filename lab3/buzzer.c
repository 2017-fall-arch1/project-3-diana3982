#include <msp430.h>
#include "buzzer.h"
#include "libTimer.h"

static unsigned int period = 1000;
static signed int rate = 200;

#define MIN_PERIOD 1000
#define MAX_PERIOD 4000

/* the following code is pulled from lab 2 */
void buzzer_init(){
  timerAUpmode();
  P2SEL2 &= ~(BIT6 | BIT7);
  P2SEL &= ~BIT7;
  P2SEL |= BIT6;
  P2DIR = BIT6;

  make_sound();
}

void buzzer_set_period(short cycles){
  CCR0 = cycles;
  CCR1 = cycles >> 1;
}
void buzzer_advance_frequency(){
  period += rate;
  if((rate > 0 && (period > MAX_PERIOD)) ||
     (rate < 0 && (period < MIN_PERIOD))){
    rate =- 1000;
    period += (rate<< 1);
  }
}

/* the following determines if hit or point */
void make_sound(int x){
  switch(x){
  case 0:
    buzzer_set_period(1000);
  case 1:
    buzzer_advance_frequency(3000);
  }
}
