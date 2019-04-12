#include "Student.h"

using namespace std;
using namespace hw4;

Student::Student(int newTime){timeToWait=newTime;}
Student::Student(){}
void Student::incrementStudent(){
  timeToWait--;
  timeSpentWaiting++;
}
