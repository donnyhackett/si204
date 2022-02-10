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

  //INSTRUCTIONS
  //First day of sim is Sunday
  //Every other Friday, paycheck is deposited
  //withdrawls happen during the day before end of day balance is calculated

  //Input check function
  string temp, cmd, file;
  int n;
  double over;
  cin >> cmd;
  while(cmd != "run"){
	  cin >> temp >> over;
	  if (cmd == "initibal")
	  	initibal = over;
	  else if(cmd == "loanrate")
	  	loanrate = over;
  	  else if(cmd == "paycheck")
	  	paycheck = over;
	  else if(cmd == "saverate")
		saverate = over;
	  else{
		cout << "Unknown command \"" << cmd << "\"" << endl;
	  	return 4;
	  }
	  cin >> cmd;
  }
  if(!(cin >> n >> file)){
	  cout << "Expected : run N file" << endl;
	  return 1;
  }

  //File check function
  ifstream fin(file);
  if(!fin){
	  cout << "File \"" << file << "\" not found!" << endl;
	  return 2;
  }

  //Burn off garbage
  fin >> temp >> temp >> temp;  

  //Main function
  cout << "initibal = " << initibal << endl;
  cout << "paycheck = " << paycheck << endl;
  cout << "saverate = " << saverate << endl;
  cout << "loanrate = " << loanrate << endl;
  double balance = initibal;
  double avg_tot;
  double expense;
  for(int i = 0; i < (n*7); i++){
	  if((i % 14) == 12)
		  balance += paycheck;
	  if(!(fin >> expense)){
		  cout << "Insufficient values in \"" << file << "\"" << endl;
		  return 3;
	  }
	  balance -= expense;
  	  avg_tot += balance;
  }
  cout << "Ending balance = " << balance << endl;
  cout << "Average end-of-day balance = " << avg_tot/(n*7) << endl;

  return 0;
}
