#ifndef Proj3_h
#define Proj3_h
#include <iostream>
#include <fstream>
using namespace std;

struct Pos
{
  int row, col;
};

char** readBoard(ifstream&);

#endif
