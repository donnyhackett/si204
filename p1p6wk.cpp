#include <iostream>
#include <fstream>
using namespace std;

int main()
{
  double weight = 0;
  string temp, type = "";
  double cost = 0.0; 
  cin >> weight >> temp >> type;
  if(weight <= 5.0)
    weight = 5.0;
  if(type == "standard")
    cost = .03 * (weight);
  else if(type == "express")
    cost = .05 * (weight);
  else
    cost = .08 * (weight);
  cout << "$" << cost << endl;
  return 0;
}
