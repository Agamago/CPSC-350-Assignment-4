#include "Counter.h"
#include <iostream>
#include <string>
using namespace std;

Counter::Counter()
{
  isEmpty=true;
}

// returns total idle time or 0
void Counter::incrementCounter(){
  if (timeRemaining<=0){ // update empty counters
    isEmpty=0;
  }
  else if(!isEmpty){ // updating other booked counters
    timeRemaining--;
  }
  else{
    timeIdle++;
  }


}
