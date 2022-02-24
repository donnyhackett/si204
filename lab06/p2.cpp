#include <iostream>
using namespace std;
#include <cstdlib>

int rand();
int roll();
int ctime();

int main()
{
    srand(time(0));
    for(int i = 0; i < 5; i++)
    {
        int first = roll();
        int second = roll();
        cout << "Player rolled " << first << " + " << second << " = " << first + second << endl;
    }
    return 0;
}

int roll()
{
    int out = 6;
    while(out > 5)
    {
        out = ((rand()) % 8);
    }
    return (out + 1);
}