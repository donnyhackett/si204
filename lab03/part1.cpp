#include <iostream>
using namespace std;

int main()
{
  string currency_1;
  string currency_2;
  double amt;
  string temp;
  cin >> temp >> amt >> currency_1 >> temp >> currency_2;
  int cur_1;
  int cur_2;
  if ((currency_1 == "Euros")||(currency_1 == "euros"))
    cur_1 = 0;
  else if ((currency_1 == "Dollars")||(currency_1 == "dollars"))
    cur_1 = 1;
  else
    cur_1 = 2;
  if ((currency_2 == "Euros")||(currency_2 == "euros"))
    cur_2 = 0;
  else if ((currency_2 == "Dollars")||(currency_2 == "dollars"))
    cur_2 = 1;
  else
    cur_2 = 2;
  if (cur_2 == 0)
  {
    if (cur_1 == 1)
      cout << amt*0.9018 << endl;
    else if (cur_1 == 2)
      cout << (amt/0.7614)*0.9018 << endl;
    else
      cout << amt << endl;
  }
  else if (cur_2 == 1)
  {
    if (cur_1 == 0)
      cout << amt/0.9018 << endl;
    else if (cur_1 == 2)
      cout << (amt/0.7614) << endl;
    else
      cout << amt << endl;
  }
  else if (cur_2 == 2)
  {
    if (cur_1 == 0)
      cout << (amt/0.9018)*0.7614 << endl;
    else if (cur_1 == 1)
      cout << amt*0.7614 << endl;
    else
      cout << amt << endl;
  }
  return 0;
}

