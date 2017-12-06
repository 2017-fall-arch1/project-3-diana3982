#include <msp430.h>
#include <buzzer.h>
static unsigned int period = 1000;
static signed int rate = 200;

#define MIN_PERIOD 1000
#define MAX_PERIOD 4000

/* the following code is pulled from lab 2 */
void buzzer_init(){
  timerAUpmode();
  P2SEL2 &= ~(BIT6 | BIT7);
  P2SEL |= BIT6;
  P2DIR = BIT6;

  buzzer_advance_frequency();
}

void buzzer_advance_frequency(){
  period += rate;
  if((rate > 0 && (period > MAX_PERIOD)) ||
     (rate < 0 && (period <MIN_PERIOD))){
    rate =-rate;
    period += (rate << 1);
  }
  buzzer_set_period(period);
}
