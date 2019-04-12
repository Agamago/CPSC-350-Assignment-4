#include "Simulation.h"
#include <iostream>
#include <string>
#include <fstream>

using namespace std;
using namespace hw4;

void Simulation::parseFile(string filename){
  string line; string stemp;
  int temp; int numStudents;

  ifstream FileStream;
  FileStream.open(filename); // loading file

  FileStream>>line; // parsing number of counters
  numCounters = stoi(line); // converting to inst and storing in numcounters
  Counter newCounters[numCounters]; // creating counters
  counters = newCounters; // assigning to pointer

  while(FileStream>>line){ // loops through times students arrive

    temp = stoi(line);
    timeQueue.enqueue(temp); // store time to arrive


    FileStream>>line; // gets numer of students
    numStudents = stoi(line);
    numStudentsQueue.enqueue(numStudents); // takes in number of students coming
    for (int x=0; x<numStudents;x++){
      FileStream>>line;
      studentQueue.enqueue(stoi(line)); // adding student to queue
    }
  }
  FileStream.close();
}

void Simulation::incrementTime(){
  int waitTime; int timeSpentWaiting; int idleTime; int counterTime;
  Student tempStu;

  // first we check if theres any students arriving
  if (timeQueue.getSize()>0){
    if (time==timeQueue.peekFront()){ // if its time for students to come
    int studentsArriving = numStudentsQueue.dequeue(); // get number of students coming
    for (int x=0; x<studentsArriving; x++){
      cout << "test";
      cout << studentQueue.getSize();
      waitTime = studentQueue.dequeue();
      Student tempStu = Student(waitTime);
      studentLine.enqueue(tempStu);
    }
  }
}

  // next we check if theres any available counters and assign students to them
  for (int x=0; x<numCounters;x++){
    if (studentLine.getSize()==0){break;} // stop once we have gone through all students
    if (counters[x].isEmpty){ // if theres an empty counter
      totalStudents++; // used for averaging

      // putting student in the counter
      tempStu = studentLine.dequeue(); // take student out of line
      counterTime = tempStu.timeToWait;
      timeSpentWaiting = tempStu.timeSpentWaiting;
      totalWaitTime+=timeSpentWaiting; // increase total time spent waiting
      studentWaitTimes.enqueue(timeSpentWaiting); // used for mean calculation
      if(timeSpentWaiting>5){overFive++;}
      if(timeSpentWaiting>10){overTen++;}

      // counter finessing
      idleTime = counters[x].timeIdle;
      counters[x].timeIdle=0; // resetting idle time
      if (idleTime>longestIdleTime){longestIdleTime=idleTime;} // updating longest idle time
      totalIdleTime+=idleTime; totalIdles++; // total idle time and amount of idles for mean
      if (idleTime>5){idleOverFive++;}
    }
  }

  // updating remaining students
  Node<Student> *tempNode = studentLine.queueList.head; // starting with first node
  for (int x=0;x<studentLine.getSize();x++){
    tempNode->data.incrementStudent();
    tempNode = tempNode->next;
  }

  // updaing counters
  for (int x=0; x<numCounters;x++){
    counters[x].incrementCounter();
  }

  // incrementing time
  time++;
}

void Simulation::beginSimulation(){
  bool running = true;
  bool allEmpty = false; // if all the counters are empty

  while(running){
    incrementTime();
    printStatus();

    // checking if counters are empty
    allEmpty=true;
    for(int x=0;x<numCounters;x++){
      cout << "All empty iter: " << x << " isEmpty: " << counters[x].isEmpty << endl;
      cout << "Time left: " << counters[x].timeRemaining << endl;
      if(counters[x].isEmpty){
        allEmpty=false;
      }
    }
    cout << "All empty: " << allEmpty << endl;
    // if there's no one in line, no one yet to arrive, or no one in counters
    if (studentLine.getSize()<=0 && studentQueue.getSize()<=0 && allEmpty){
      running=false;
    }
  }
}

void Simulation::printStatus(){
  cout << "Time: " << time << endl;
  cout << "Student line: ";
  //studentLine.displayQueue();
  cout << endl << "Student Queue: ";
  cout << endl;
}
