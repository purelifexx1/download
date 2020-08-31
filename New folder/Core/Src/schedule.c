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
  t = HAL_GetTick();
  
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
  t = HAL_GetTick();
}

void schedule::looping()
{
  if((unsigned long)(HAL_GetTick() - t) >= T && enable == true) {
    t = HAL_GetTick();
    enable = (status == false)?true:false;
    this->callback_function();    
  }
}
