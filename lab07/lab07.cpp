#include <iostream>
#include <fstream>
using namespace std;

void cprintchar(char, char);
void cprintstr(string, string);
void markmatch(string&, string&);
int findfirst(char, string);
void marksemimatch(int, string&, string&);

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

    //p3
    string s1 = "livingstone";
    string s2 = "riverratses";
    cout << s1 << endl << s2 << endl;
    markmatch(s1,s2);
    cout << s1 << endl << s2 << endl;

    //p4
    string u = "favoritism";
    cout << findfirst('f',u) << endl; // f is 1st letter (index 0)
    cout << findfirst('x',u) << endl; // x not in word
    cout << findfirst('i',u) << endl; // must find first i

    //p5
    cout << "i = 0 ... semi-match found" << endl;
    string v1 = "react";
    string v2 = "drear";
    cprintstr(v1,"*...."); cout << " " << v2 << endl;
    marksemimatch(0,v1,v2);
    cout << v1 << " " << v2 << endl;
    cout << "i = 1 ... no semi-match found" << endl;
    string x1 = "tarry";
    string x2 = "scone";
    cprintstr(x1,".*..."); cout << " " << x2 << endl;
    marksemimatch(1,x1,x2);
    cout << x1 << " " << x2 << endl;
    cout << "i = 2 ... ignore *'s" << endl;
    string y1 = "cr*st";
    string y2 = "sc*ne";
    cprintstr(y1,"..*.."); cout << " " << y2 << endl;
    marksemimatch(2,y1,y2);
    cout << y1 << " " << y2 << endl;

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
    for(int i = 0; i < s.length(); i++)
        cprintchar(s[i], t[i]);
}

void markmatch(string& s1, string& s2)
{
    for(int i = 0; i < s1.length(); i++)
    {
        if(s1[i] == s2[i])
            s1[i] = s2[i] = '*';
    }
}

int findfirst(char c, string s)
{
    for(int i = 0; i < s.length(); i++)
    {
        if(s[i] == c)
            return i;
    }
    return -1;
}

void marksemimatch(int i, string& s1, string& s2)
{
    char c;
    c = s1[i];
    if (c == '*')
        return;
    for(int j = 0; j < s2.length(); j++)
    {
        if(s2[j] == c)
        {
            if(c != '*')
            {
                s2[j] = s1[i] = '+';
                return;
            }
        }
    }
}


