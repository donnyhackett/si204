#include <iostream>
#include <fstream>
using namespace std;

int length(int);
void rep(int, char, int, ostream&);
void writefrac(int, int, int, ostream&);

int main()
{
    string temp, file;
    char t;
    int num, denom;
    cin >> temp >> num >> t >> denom >> file;
    ofstream OUT(file);
    if(file == "screen")
        writefrac(0, num, denom, OUT);
    else
        writefrac(1, num, denom, OUT);
    return 0;
}

void writefrac(int type, int num, int denom, ostream& OUT)
{
    int l = length(denom);
    int n = length(num);
    for(int i = 0; i < l; i++)
    {
        if(i == ((l - n)/2))
        {
            if(type == 0)
                cout << num;
            else
                OUT << num;
            break;
        }
        else
            if(type == 0)
                cout << " ";
            else
                OUT << " ";
            
    }
    if(type == 0)
        cout << endl;
    else
        OUT << endl;
    rep(type, '-', l, OUT);
    if(type == 0)
        cout << endl << denom << endl;
    else
        OUT << endl << denom << endl;
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

void rep(int type, char c, int k, ostream& OUT)
{
    if(type == 0)
    {
        for(int i = 0; i < k; i++)
        {
            cout << c;
        }
        return;
    }
    for(int i = 0; i < k; i++)
    {
        OUT << c;
    }
}