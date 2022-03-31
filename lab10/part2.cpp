#include <cstdlib>
#include <iostream>
#include <string>
using namespace std;


// prints the elements of array A (that has N elements) from index i to the end
// should be space separated, and there should be a newline at the end.
void printspaced(int* A, int i, int N);
void printspaced(string* A, int i, int N);
int isThere(string* A, int N, string x);
bool match(string y, string x);
void addKey(string* A, int N, string x);
void removeKey(string* A, int N, string x);
bool before(string a, string b, string* keys);
void sortArray(string* A, int N, string* keys);
void printArray(string* A, int N);

int main(int argc, char** argv)
{
    /*
    // if run with a command-line argument x, seed with x (else use current time)
    srand(argc < 2 ? time(0) : atoi(argv[1]));

    // Create a randomish array to use as input to printspaced
    int N = 10 + rand() % 20, K = N / (2 + rand() % 5);
    int *A = new int[N];
    for(int i = 0; i < N; i++)
    A[i] = i % K;
    */
    // Call printspaced (and cross fingers!)

    //make the parent array of keyboard
    string *keys = new string[59];
    int j = 6;
    for(int i = 0; i < 59; i++)
    {
        keys[i] = "";
        keys[i].append(1, char(65 + (i % 7)));
        keys[i].append(1, char(48 + (j / 7)));  
        j++;
    }

    //make on/off array
    int N = 12; //12 because max amt of on possible
    string *onoff = new string[N]; 
    for(int i = 0; i < N; i++)
    {
        onoff[i] = "";
    }

    //take in input strings while not quit
    string in1, in2;
    cin >> in1;
    while(in1 != "quit")
    {
        cin >> in2;
        
        //turn on/off
        if(in1 == "on")
        {
            if(isThere(onoff, N, in2) == N)
            {
                addKey(onoff, N, in2);
            }
        }
        else if(in1 == "off")
        {
            if(isThere(onoff, N, in2) != N)
            {
                removeKey(onoff, N, in2);
            }
        }

        //sort array
        sortArray(onoff, N, keys);
        
        //print array
        printArray(onoff, N);

        cin >> in1;
    }

    return 0;
}

void printspaced(int* A, int i, int N)
{
    if(i == N - 1)
        cout << A[i] << endl;
    else
    {
        cout << A[i] << " ";
        printspaced(A, i + 1, N);
    }
}
void printspaced(string* A, int i, int N)
{
    if(i == N - 1)
        cout << A[i] << endl;
    else
    {
        cout << A[i] << " ";
        printspaced(A, i + 1, N);
    }
}

int isThere(string* A, int N, string x)
{
    int i = 0;
    while(i < N && !match(A[i],x))
        i++;
    return i;
}

bool match(string y, string x)
{
    return y == x;
}

void addKey(string* A, int N, string x)
{
    int i = 0;
    for(; A[i] != ""; i++){}

    A[i] = x;
}

void removeKey(string* A, int N, string x)
{
    int index = isThere(A, N, x);
    A[index] = "";
}

bool before(string a, string b, string* keys)
{
    if(a == "")
        return true;
    if(b == "")
        return false;
    return (isThere(keys, 59, a) < isThere(keys, 59, b));
}

void sortArray(string* A, int N, string* keys)
{
    for(int length = N; length > 1; length--)
    {
        int max = 0, i;
        for(i = 1; i < length; i++)
            if(before(A[max], A[i], keys))
                max = i;
        string temp = A[max];
        A[max] = A[length - 1];
        A[length - 1] = temp;
    }
}

void printArray(string* A, int N)
{
    cout << "[";
    int i = 0;
    for(; A[i] == ""; i++){}
    for(;i < N; i++)
    {
        if(i == N - 1)
        {
            cout << A[i] << "]" << endl;
            return;
        }
        else
            cout << A[i] << " ";
    }
    cout << "]" << endl;
}