#include <iostream>
#include <string>
using namespace std;

class Counter
{
  public:
    Counter();
    bool isEmpty=true;
    int timeRemaining=0; int timeIdle=0;
    void incrementCounter();
  private:

};
