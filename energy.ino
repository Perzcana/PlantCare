#include <avr/sleep.h>
#include <avr/wdt.h>


void Sleep_avr(){
    set_sleep_mode(SLEEP_MODE_PWR_DOWN  ); // sleep mode is set here
    sleep_enable();
    sleep_mode();                        // System sleeps here
}

bool isReadyWake(){
   if (data >= CALL_TIMES){
     data = 0;
   }
   return !data;
   //return !(data = data>=CALL_TIMES?0:data);
}

void setup_watchdog(int ii) {
    byte bb;
    if (ii > 9 ) ii=9;
    bb=ii & 7;
    if (ii > 7) bb|= (1<<5);
    bb|= (1<<WDCE);
    
    MCUSR &= ~(1<<WDRF);
    // start timed sequence
    WDTCSR |= (1<<WDCE) | (1<<WDE);
    // set new watchdog timeout value
    WDTCSR = bb;
    WDTCSR |= _BV(WDIE); 
}

void energy_init(){
    setup_watchdog(TIME_PER_SLEEP);
// 0=16ms, 1=32ms,2=64ms,3=128ms,4=250ms,5=500ms
// 6=1 sec,7=2 sec, 8=4 sec, 9= 8sec
    ACSR |=_BV(ACD);//OFF ACD
    ADCSRA=0;//OFF ADC
    //Sleep_avr();//Sleep_Mode
    #ifdef DEBUG
      Serial.println("energy_init");
    #endif
}

ISR(WDT_vect) {
    ++data;
    #ifdef DEBUG
      Serial.println("ISR");
    #endif
    // wdt_reset();
}
