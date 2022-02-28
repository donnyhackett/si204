#include <iostream>
using namespace std;

int ellapsed(int, int, int);
int queryTime(int);

int main()
{
  int t1, t2;
  t1 = queryTime(1);
  t2 = queryTime(2);

  int ellapsed = t2 - t1;
  cout << "Ellapsed time is " << ellapsed << " seconds" << endl;

  return 0;
}

int ellapsed(int hour, int minute, int second)
{
  return (hour*60 +minute)*60 + second;
}

int queryTime(int i)
{
  if (i == 1)
    cout << "Enter first time: ";
  else
    cout << "Enter second time: ";
  int t1;
  int h1, m1, s1;
  char c1;
  cin >> h1 >> c1 >> m1 >> c1 >> s1;
  return ellapsed(h1, m1, s1);
}