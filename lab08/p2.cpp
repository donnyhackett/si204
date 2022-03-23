#include <iostream>

using namespace std;

void print(int*, int);
bool isInOrder(int*, int);
int* read(int&);
void command(int*, int, int&, int&);
void reverse(int*, int, char, char);
void swap(int*, int, char, char);
void prntScore(int, int);

int main()
{
    int moves = 0, score = 0;
    cout << "Welcome to PutInOrder!" << endl;
    cout << "board> ";
    int N;
    int *A = read(N);
    while(!isInOrder(A,N))
    {
        cout << endl;
        print(A, N);
        command(A, N, score, moves);
    }
    cout << endl;
    print(A, N);
    prntScore(moves, score);
    delete [] A;
    return 0;
}

void print(int* i, int j)
{
    for(int k = 0; k < j; k++)
        cout << " " << i[k];
    cout << endl;
    for(int k = 0; k < ((j*2) + 1); k++)
        cout << "-";
    cout << endl;
    for(int k = 0; k < j; k++)
        cout << " " << char(65 + k);
    cout << endl;
}

bool isInOrder(int* i, int j)
{
    int least = i[0];
    for(int k = 0; k < j; k++)
    {
        if(i[k] < least)
            return false;
        least = i[k];
    }
    return true;
}

int* read(int& i)
{
    char temp;
    cin >> temp >> temp >> i >> temp;
    int* j = new int[i];
    for(int k = 0; k < i; k++)
    {
        cin >> j[k];
    }
    return j;
}

void command(int* i, int j, int& score, int& moves)
{
    cout << "> ";
    string cmd;
    char c1, c2;
    cin >> cmd;
    if(cmd == "help")
    {
        cout << "PutInOrder!  The goal is to order from smallest to largest with the lowest score." << endl;
        cout << "The moves are:" << endl;
        cout << "swap x y    - swaps the values in column x and column y" << endl;
        cout << "Scoring: swap = 3pts" << endl;
    }
    else if(cmd == "reverse")
    {
        cin >> c1 >> c2;
        reverse(i,j,c1,c2);
        score += 2;
        moves ++;
    }
    else if(cmd == "swap")
    {
        cin >> c1 >> c2;
        swap(i,j,c1,c2);
        score += 3;
        moves ++;
    }
    else
    {
        cout << "Unknown move '" << cmd << "'" << endl; 
    }
}

void reverse(int* i, int j, char c1, char c2)
{
    int* n = new int[j];
    int first = int(c2 - 65);
    int second = int(c1 - 65);
    if(first > second)
    {
        int tmp = first;
        first = second;
        second = tmp;
    }
    int cnt = second;
    for(int k = 0; k < j; k++) // copy array values
    {
        n[k] = i[k];
    }
    for(int k = first; k <= second; k++) // swap array values
    {
        n[k] = i[cnt];
        cnt--;
    }
    for(int k = 0; k < j; k++) // copy array values
    {
        i[k] = n[k];
    }
}

void swap(int* i, int j, char c1, char c2)
{
    int first = i[int(c1 - 65)];
    int second = i[int(c2 - 65)];
    i[c2 - 65] = first;
    i[c1 - 65] = second;
}

void prntScore(int moves, int score)
{
    cout << score << " points! (" << moves << " moves)" << endl;
}