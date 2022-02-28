#include <iostream>
using namespace std;

int gcd(int, int);

int main()
{
    string temp = "";
    int term1, term2;
    char x;
    while(x != ';')
    {
        cin >> term1;
        for(int i = 0; i < 2; i++)
        {
            if(i == 1)
            {
                cin >> term2;
            }
            if(i == 0)
            {
                cin >> x;
            }
        }
        if(gcd(term1, term2) > 1)
            cout << term1 << x << term2 << " is not in lowest terms!" << endl;
        cin >> x;
        term1 = 0;
        term2 = 0;
    }
    return 0;
}

int gcd(int i, int j)
{
    int k, l, remain = 0;
    if(i > j)
    {
        k = i;
        l = j;
    }
    else
    {
        k = j;
        l = i;
    }
    while(l != 0)
    {
        remain = k%l;
        k = l;
        l = remain;
    }
    return k;
}