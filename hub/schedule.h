#ifndef INC_SCHEDULE_
#define INC_SCHEDULE_
#include <Arduino.h>
#define Callback void(*callback_function)()
class schedule
{
  private:
    Callback;    
    int T;
    unsigned long t = 0;
    bool enable = false;
    bool status = false;
  public:
    schedule();
    void start_timeout(Callback, int timeout);
    void start_interval(Callback, int cycle);
    void stop_timer();   
    void looping(); //alway put this in loop
};

#endif
