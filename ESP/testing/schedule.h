#ifndef INC_SCHEDULE_
#define INC_SCHEDULE_
#include "mySerial.h"
#include <Arduino.h>
#define Callback void(*callback_function)()
class schedule
{
  private:
    Callback;    
    int T;
    unsigned long t = 0;
    bool enable = false;
  public:
    schedule(int Timer);
    void start_timer();
    void stop_timer();
    void set_callback(Callback);
    void looping();
};

#endif
