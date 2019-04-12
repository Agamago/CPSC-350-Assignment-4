#include <iostream>
#include "Simulation.h"
using namespace std;
using namespace hw4;

int main(int argc, char *argv[]){
  Simulation theWorld;
  theWorld.parseFile("input.txt");
  theWorld.beginSimulation();

}
