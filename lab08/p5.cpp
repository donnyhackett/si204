#include <iostream>
#include <fstream>

using namespace std;

void print(int*, int);
bool isInOrder(int*, int);
int* read(int&);
void command(int*, int, int&, int&);
void reverse(int*, int, char, char);
void swap(int*, int, char, char);
void prntScore(int, int);
int findMax(int*, int);
void cycle(int*, int, int);

int main()
{
    int moves = 0, score = 0;
    cout << "Welcome to PutInOrder!" << endl;
    cout << "board> ";
    int N;
    int *A = read(N);
    while(!isInOrder(A, N))
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
    int l = 0;
    int max = findMax(i, j);
    for(int k = max; k > 0; k--)
    {
        for(int m = 0; m < ((j*2) + 1); m++)
        {
            if(m % 2 == 0)
                cout << " ";
            else
            {
                if(i[l] >= k)
                    cout << '#';
                else
                    cout << " ";
                l++;
            }
        }
        l = 0;
        cout << endl;
    }
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
    string temp;
    cin >> temp;
    if(temp != "N")
    {
        ifstream fin(temp);
        fin >> temp >> temp >> i >> temp;
        int* j = new int[i];
        for(int k = 0; k < i; k++)
        {
            fin >> j[k];
        }
        return j;
    }
    else
    {
        cin >> temp >> i >> temp;
        int* j = new int[i];
        for(int k = 0; k < i; k++)
        {
            cin >> j[k];
        }
        return j;
    }
}

void command(int* i, int j, int& score, int& moves)
{
    cout << "> ";
    string cmd;
    char c1, c2;
    int num;
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
    else if(cmd == "cycleleft")
    {
        cin >> num;
        cycle(i,j,num);
        score ++;
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

void cycle(int* i, int j, int num)
{
    int* n = new int[j];
    for(int m = 0; m < num; m++)
    {
        for(int k = 0; k < j; k++) // copy array values
        {
            n[k] = i[k];
        }
        for(int k = 0; k < j; k++) // swap array values
        {
            n[k] = i[(k + 1) % j];
        }
        for(int k = 0; k < j; k++) // copy array values
        {
            i[k] = n[k];
        }
    }
}

void prntScore(int moves, int score)
{
    cout << score << " points! (" << moves << " moves)" << endl;
}

int findMax(int* i, int j)
{
    int max = 0;
    for(int k = 0; k < j; k++)
    {
        if(i[k] > max)
            max = i[k];
    }
    return max;
}