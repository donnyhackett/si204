#include <iostream>
#include <fstream>
using namespace std;

int main()
{
  int in;
  string offset = "";
  cin >> in;
  for (int i = in; i > 0; i--){
    cout << offset;
    offset += " ";
    for(int j = 0; j < i; j++)
      cout << i;
    cout << endl;
  }
  return 0;
}
