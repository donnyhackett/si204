#include <iostream>
using namespace std;

// I want a function harm(n) that computes the nth harminic number, which
// is 1/1 + 1/2 + 1/3 + ... + 1/n.  Can you make it for me?
// Add the prototype and definition to this file that makes the program work.

double harm(int i);

int main()
{
  double x, H = 0;
  cout << "Enter x: ";
  cin >> x;
  int i = 0;
  do {
    i++;
    H = harm(i); //-- here's where I use harm!
  } while(H < x);

  cout << "the " << i << "th harmonic number is " << H
       << ", which is the first greater than " << x << endl;

  return 0;
}
double harm(int i)
{
  double x = 0;
  for(double j = 0; j < i; j++)
  {
    x += (1/(j + 1));
  }
  return x;
}





