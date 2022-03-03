/************************************************
 ** This program reads in two temperatures, both
 ** greater than 0C/32F and less than 360C/680F,
 ** and it outputs the change in energy (in
 ** kilo joules) of 1kg of water going from the
 ** initial temp to final.
 ** NOTE: this program needs the file enth.txt.
 ************************************************/
#include <iostream>
#include <fstream>
using namespace std;

double convertC(double);
double readT();
void swapT(double&, double&);
double enthalpy(double, double);

int main()
{
  int swapped = 0;
  double Ti, Tf;

  // Read initial temperature
  cout << "Initial temperature: ";
  Ti = readT();
  
  // Read final temperature
  cout << "Final temperature: ";
  Tf = readT();

  if(Tf < Ti)
  {
      swapped = 1;
      swapT(Tf, Ti);
  }

  double delta = enthalpy(Ti, Tf);
  if (swapped == 0)
    cout << "change in energy of 1 kg water is " << delta << "kj" << endl;
  else
    cout << "change in energy of 1 kg water is " << -delta << "kj" << endl;
  return 0;
}

double convertC(double t)
{
  return (t - 32.0)*5.0/9.0;
}

double readT()
{
  double ti;
  char ui;
  cin >> ti >> ui;
  if (ui == 'C')
    return ti;
  else if (ui == 'F')
    return convertC(ti);
  else {
    cout << "Bad unit '" << ui << "'!" << endl;
    exit(1); // exits program from anywhere!
  }
}

void swapT(double& i, double& j)
{
  double temp = i;
  i = j;
  j = temp;
}

double enthalpy(double Ti, double Tf)
{
  // find enthalpy delta
    ifstream fin("enth.txt");
    bool foundi = false, foundf = false;
    double tlow, elow, thigh, ehigh, first, second;
    fin >> tlow >> elow;
    while(!foundf && fin >> thigh >> ehigh)
    {
      if (!foundi && tlow <= Ti && Ti < thigh)
      {
	first = (ehigh - elow)*(Ti - tlow)/(thigh - tlow) + elow;
	foundi = true;
      }
      else if (foundi && tlow <= Tf && Tf < thigh)
      {
	second = (ehigh - elow)*(Tf - tlow)/(thigh - tlow) + elow;
	foundf = true;
      }
    }
    return second - first;
}

