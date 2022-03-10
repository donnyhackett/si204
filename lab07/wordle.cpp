#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

void cprintchar(char, char);
void cprintstr(string, string);
void markmatch(string&, string&);
int findfirst(char, string);
void marksemimatch(int, string&, string&);
int roll();

int rand();
int ctime();

int main()
{
    srand(time(0));

    string guess, word = "test";
    int count = 1;

    ifstream fin("words.txt");
    for(int i = 0; i < roll(); i++)
        fin >> word;
    while(guess != word)
    {
        if(count == 7)
        {
            cout << "> " << word << endl;
            return 0;
        }
        cout << ": ";
        cin >> guess;

        string cword = word, cguess = guess;

        markmatch(cguess,cword);
        for(int i = 0; i < cguess.length(); i++)
            marksemimatch(i,cguess,cword);
        cout << count << " ";
        cprintstr(guess,cguess);
        cout << endl;

        count++;
    }

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

void marksemimatch(int k, string& s1, string& s2)
{
    char c;
    for(int i = 0; i < s1.length(); i++)
    {
        c = s1[i];
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
}

int roll()
{
    int out = 4595;
    while(out > 4594)
    {
        out = rand();
    }
    return (out + 1);
}


