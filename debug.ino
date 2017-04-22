#ifdef DEBUG
static unsigned long pre_time = millis();
static unsigned long curr_time = pre_time;
static volatile int times = 0;

void debug_init(){
  Serial.begin(9600);
  while(!Serial);
  Serial.println("debug_init");
  Serial.println("setup");
 }

 void debug_process(){
  times ++;
  Serial.print(state);
  Serial.print(" <-state times-> ");
  Serial.print(times);
  curr_time = millis();
  Serial.print(" ; interuupt time:");
  Serial.print(data);
  Serial.print("; time cost:");
  Serial.println(curr_time-pre_time);
  pre_time = curr_time;
  Serial.println("**delay_sleep**");
  delay(100);
 }
 #endif
