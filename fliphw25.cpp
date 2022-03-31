#include <iostream>
using namespace std;

void tri(int n, int level);
void rep(char c, int k);
void repsep(char c, int k);

int main()
{
  tri(8,8);
  return 0;
}

void tri(int n, int level)
{
  if (level == 0) 
    return;
  tri(n,level-1); 
  rep(' ',1 + n - level);
  rep('*',level);
  cout << endl;
}

void rep(char c, int k)
{ 
  if (k > 0) 
  { 
    cout << c; 
    rep(c,k-1); 
  } 
}

void repsep(char c, int k)
{
  if (k > 1) 
  { 
    cout << c << '-'; 
    repsep(c,k-1); 
  }
  else if (k == 1)
  {
    cout << c; 
    repsep(c,k-1);
  } 
}

