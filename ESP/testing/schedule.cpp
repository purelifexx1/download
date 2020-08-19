#include "schedule.h"

schedule::schedule(int Timer)
{
  T = Timer;
}
void schedule::start_timer()
{
  t = millis();
  enable = true;
}
void schedule::stop_timer()
{
  enable = false;
}
void schedule::set_callback(Callback)
{
  this->callback_function = callback_function;
}

void schedule::looping()
{
  if((unsigned long)(millis() - t) >= T && enable == true) {
    t = millis();
    this->callback_function();
  }
}
