#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
using namespace std;

void readA(char**, ifstream&);
void printA(char**);
void deleteA(char**);

int main()
{
  ifstream fin("letters.txt");

  // Read A
  char** L0 = new char*[4];
  readA(L0, fin);

  // Read N
  char** L1 = new char*[4];
  readA(L1, fin);

  // Read V
  char** L2= new char*[4];
  readA(L2, fin);

  // Read Y
  char** L3 = new char*[4];
  readA(L3, fin);

  // Print N
  printA(L1);

  // Print A
  printA(L0);

  // Print V
  printA(L2);

  // Print Y
  printA(L3);

  deleteA(L0);
  deleteA(L1);
  deleteA(L2);
  deleteA(L3);

  return 0;
}

void readA(char** A, ifstream& fin)
{
  for(int i = 0; i < 4; i++)
    A[i] = new char[7];
  for(int i = 0; i < 4;i++)
  {
    for(int j = 0; j < 7; j++)
      A[i][j] = fin.get();
    while(fin.get() != '\n');
  }  
}

void printA(char** A)
{
  for(int i = 0; i < 4;i++)
  {
    for(int j = 0; j < 7; j++)
      cout << A[i][j];
    cout << endl;
  }  
  cout << endl;
}

void deleteA(char** A)
{
  for (int i = 0; i < 4; i++)
    delete [] A[i];
  delete [] A;
}