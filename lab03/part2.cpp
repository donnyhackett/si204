#include <iostream>
using namespace std;

int main()
{
  string currency_1;
  string currency_2;
  string c1;
  string c2;
  string c3;
  string c4;
  string c5;
  double amt;
  string temp;
  cin >> temp >> amt >> c1; 
  if ((c1 == "Dollars")||(c1 == "dollars"))
  {  
    cin >> c2 >> c3 >> c4;
    if ((c4 == "Dollars")||(c4 == "dollars"))
      cin >> c5;
  }
  else
  {
    cin >> c2 >> c3;
    if ((c3 == "Dollars")||(c3 == "dollars"))
      cin >> c4;
  }

  int cur_1;
  int cur_2;
  if ((c1 == "Dollars")||(c1 == "dollars"))
  {
    if ((c2 == "US")||(c2 == "us"))
      cur_1 = 1;
    else 
      cur_1 = 3;
    if ((c4 == "Dollars")||(c4 == "dollars"))
    {      
      if ((c5 == "US")||(c5 == "us"))
        cur_2 = 1;
      else
        cur_2 = 3;
    }
    else if ((c4 == "Euros")||(c4 == "euros"))
      cur_2 = 0;
    else
      cur_2 = 2;
  }
  else if ((c3 == "Dollars")||(c3 == "dollars"))
  {
    if ((c4 == "US")||(c4 == "us"))
      cur_2 = 1;
    else 
      cur_2 = 3;
    if ((c1 == "Euros")||(c1 == "euros"))
      cur_1 = 0;
    else
      cur_1 = 2;
  }
  else
  {
    if ((c1 == "Euros")||(c1 == "euros"))
      cur_1 = 0;
    else
      cur_1 = 2;
    if ((c3 == "Euros")||(c3 == "euros"))
      cur_2 = 0;
    else
      cur_2 = 2;
  }
  
  if (cur_2 == 0)
  {
    if (cur_1 == 1)
      cout << amt*0.9018 << endl;
    else if (cur_1 == 2)
      cout << (amt/0.7614)*0.9018 << endl;
    else if (cur_1 == 3)
      cout << (amt/1.3156)*0.9018 << endl;
    else
      cout << amt << endl;
  }
  else if (cur_2 == 1)
  {
    if (cur_1 == 0)
      cout << amt/0.9018 << endl;
    else if (cur_1 == 2)
      cout << (amt/0.7614) << endl;
    else if (cur_1 == 3)
      cout << amt/1.3156 << endl;
    else
      cout << amt << endl;
  }
  else if (cur_2 == 2)
  {
    if (cur_1 == 0)
      cout << (amt/0.9018)*0.7614 << endl;
    else if (cur_1 == 1)
      cout << amt*0.7614 << endl;
    else if (cur_1 == 3)
      cout << (amt/1.3156)*0.7614 << endl;
    else
      cout << amt << endl;
  }
  else if (cur_2 == 3)
  {
    if (cur_1 == 0)
      cout << (amt/0.9018)*1.3156 << endl;
    else if (cur_1 == 1)
      cout << amt*1.3156 << endl;
    else if (cur_1 == 2)
      cout << (amt/0.7614)*1.3156 << endl;
    else
      cout << amt << endl;
  }
  return 0;
}

