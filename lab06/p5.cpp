#include <iostream>
#include <fstream>
using namespace std;
#include <cstdlib>

int rand();
int roll();
int ctime();
int throw1(int);
bool playAgainQuery();

int main()
{
    srand(time(0));
    int state = 1, count = 1, game = 0, bal = 0, housebal = 0, balout = 0;
    bool done = false;
    string ud;
    char temp;
    while(!done)
    {
        while(state > 0)
        {
            cout << "Round " << count << ": ";
            state = throw1(count);
            if(state == -1)
            {
                housebal += 5;
                bal -= 5;
            }
            else if(state == 0)
            {
                bal += 5;
            }
            count ++;
        }
        ofstream fout("history.txt");
        ifstream fin("history.txt");
        while(fin >> temp)
            fout << 0x08;
        if(bal > 0)
        {
            ud = "up";
            balout = bal;
        }
        else
        {
            balout = bal * -1;
            ud = "down";
        }
        count = 1;
        game++;
        if(bal == 0)
        {
            cout << "You've played " << game << " times, and are dead even." << endl;
        }
        else
            cout << "You've played " << game << " times, and are " << ud << " $" << balout << "." << endl;
        done = playAgainQuery();
        state = 1;
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

// throw1() returns -1, 0 or a positive number.
// -1 means house wins, 0 means player wins, a positive number
// means neither won, and the number is the sum of the two dice rolls
int throw1(int r)
{
    int first = roll();
    int second = roll();
    int sp;
    if(r == 1)
    {
        ofstream fout("history.txt");
        sp = first + second;
        fout << sp;
    }
    else
    {
        ifstream fin("history.txt");
        fin >> sp;
    }
    if(r == 1)
    {
        if(((first + second) == 7) || ((first + second) == 11))
        {
            cout << "Player rolled " << first << " + " << second << " = " << first + second << " Player wins!" << endl;
            return 0;
        }
        else if(((first + second) == 2) || ((first + second) == 3) || ((first + second) == 12))
        {
            cout << "Player rolled " << first << " + " << second << " = " << first + second << " House wins!" << endl;    
            return -1;
        }
        else
        {
            cout << "Player rolled " << first << " + " << second << " = " << first + second << " ... no winner, setpoint is " << sp << "!" << endl;
            return (first + second);
        }
    }
    else
    {
        if(((first + second) == sp))
        {
            cout << "Player rolled " << first << " + " << second << " = " << first + second << " Player wins!" << endl;
            return 0;
        }
        else if(((first + second) == 2) || ((first + second) == 3) || ((first + second) == 12) || ((first + second) == 7))
        {
            cout << "Player rolled " << first << " + " << second << " = " << first + second << " House wins!" << endl;    
            return -1;
        }
        else
        {
            cout << "Player rolled " << first << " + " << second << " = " << first + second << " ... no winner, roll again!" << endl;
            return (first + second);
        }
    }
}

// reports to user, asks whether they want to continue, returns true
// if they do, and false if they want to stop.
bool playAgainQuery()
{
    cout << "Would you like to play again? (y/n) ";
    char in;
    cin >> in;
    if(in == 'y')
        return false;
    return true;
}