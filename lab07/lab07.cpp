#include <iostream>
#include <fstream>
using namespace std;

void cprintchar(char, char);
void cprintstr(string, string);

int main()
{
    //p1
    cout << "[";
    cprintchar('a','*');
    cprintchar('b','.');
    cprintchar('c','+');
    cout << "]" << endl;

    //p2
    string w1 = "festering";
    string m1 = "l++g*ab+*";
    cout << "[";
    cprintstr(w1,m1);
    cout << "]" << endl;
    string w2 = "levelwises";
    string m2 = "**ug++b*er";
    cout << "[";
    cprintstr(w2,m2);
    cout << "]" << endl;
    return 0;
}

void cprintchar(char c, char d)
{
    switch(d)
    {
        //green
        case '*':
            cout << "\033[1;32m" << c << "\033[0m";
            return;
        //yellow
        case '+':
            cout << "\033[1;33m" << c << "\033[0m";
            return;
        //white
        default:
            cout << "\033[1;37m" << c << "\033[0m";
            return;
    }
}

void cprintstr(string s, string t)
{
    char c, d;
    ofstream out(s);
    ofstream out2(t);
    out << s;
    out2 << t;
    ifstream in(s);
    ifstream in2(t);
    while(in >> c && in2 >> d)
    {
        cout << "ran" << endl;
        cprintchar(c, d);
    }
}