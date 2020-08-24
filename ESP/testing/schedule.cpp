#include "schedule.h"

schedule::schedule()
{
}
void schedule::start_timeout(Callback, int timeout)
{
  T = timeout;
  enable = true;
  this->callback_function = callback_function;
  status = true;
  t = millis();
  
}
void schedule::stop_timer()
{
  enable = false;
}
void schedule::start_interval(Callback, int cycle)
{
  T = cycle;
  enable = true;
  this->callback_function = callback_function;
  status = false;
  t = millis();
}

void schedule::looping()
{
  if((unsigned long)(millis() - t) >= T && enable == true) {
    t = millis();
    enable = (status == false)?true:false;
    this->callback_function();    
  }
}
