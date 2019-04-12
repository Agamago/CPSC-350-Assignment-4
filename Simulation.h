#include "Queueue.h"
#include "Counter.h"
#include <stdlib.h>

using namespace std;

namespace hw4{
  class Simulation{
  public:
    void parseFile(string filename);
    void beginSimulation();
    void resetSimulation();
    int numCounters;
    Queueue<int> studentQueue; Queueue<Student> studentLine;
    Queueue<int> timeQueue; Queueue<int> studentWaitTimes;
    void printStatus();
  private:
    Queueue<int> numStudentsQueue;
    int time=1; int totalWaitTime; int totalStudents;
    Counter *counters;
    int overFive; int overTen;
    int meanTime; int medianTime;
    int totalIdleTime; int totalIdles;
    int meanIdleTime; int longestIdleTime; int idleOverFive;
    bool counterIsAvailable();
    void incrementTime();
  };
}
