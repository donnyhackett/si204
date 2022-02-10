#include <iostream>
#include <fstream>
using namespace std;

int main()
{
  //default values
  double paycheck = 550.00;
  double initibal = 700.00;
  double saverate = 4.0;
  double loanrate = 14.0;

  //First day of sim is Sunday
  //Every other Friday, paycheck is deposited

  //Input check function
  string cmd, file;
  int n;
  if(!(cin >> cmd >> n >> file)){
	  cout << "Expected : run N file" << endl;
	  return 1;
  }
  //Main function
  double balance = initibal;
  double avg_tot;
  for(int i = 0; i < (n*7); i++){
	if((i % 14) == 12)
		balance += paycheck;
  	avg_tot += balance;
  }
  cout << "Ending balance = " << balance << endl;
  cout << "Average end-of-day balance = " << avg_tot/(n*7) << endl;

  return 0;
}
