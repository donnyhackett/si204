#include <iostream>
using namespace std;

int length(int);
void rep(char, int, ostream);
void writefrac();

int main()
{

    return 0;
}

void writefrac()
{

}

// YOU MAY FIND THIS HELPFUL	  
int length(int n)
{
  // find length ignoring minus sign
  int M = n, L;
  for(L = 0; M != 0; L++)
    M = M / 10;

  // return, but correct for 0 & -
  return n <= 0 ? L + 1 : L;
}

void rep(char c, int k, ostream& OUT)
{
    for(int i = 0; i < k; i++)
    {
        OUT << c;
    }
}