#include <iostream>

using namespace std;

void print(int*, int);
bool isInOrder(int*, int);
int* read(int&);

int main()
{
    int N;
    int *A = read(N);
    print(A,N);
    if(isInOrder(A,N))
        cout << "Is in order!" << endl;
    else
        cout << "Is not in order!" << endl;
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