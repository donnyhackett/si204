#include <iostream>
#include <fstream>

#define length 10

using namespace std;

int find(string* b, int n, string item);

int main()
{
    string file;
    cin >> file;
    ifstream fin(file);

    char** array = new char*[length];
    for(int i = 0; i < length; i++)
        array[i] = new char[length];
    
    for(int i = 0; i < length; i++)
    {
        for(int j = 0; j < length; j++)
        {
            fin >> array[i][j];
        }
    }
    cout << "  0 1 2 3 4 5 6 7 8 9" << endl;
    for(int i = 0; i < length; i++)
    {
        cout << i << " ";
        for(int j = 0; j < length; j++)
        {
            if(j == length - 1)
                cout << array[i][j];
            else
                cout << array[i][j] << " ";
        }
        cout << endl;
    }
    
    string command;
    int index;
    cin >> command;

    while(command != "quit")
    {
        cin >> index;

        if(command == "row")
        {
            for(int i = 0; i < length; i++)
                cout << array[index][i];
        }
        else if(command == "col")
        {
            for(int i = 0; i < length; i++)
                cout << array[i][index];
        }
        else if(command == "revrow")
        {
            for(int i = length - 1; i >= 0; i--)
                cout << array[index][i];
        }
        else if(command == "revcol")
        {
            for(int i = length - 1; i >= 0; i--)
                cout << array[i][index];
        }
        cout << endl;
        cin >> command;
    }

    return 0;
}

int find(string* a, int n, string item)
{
    for(int i = 0; i < n; i++)
    {
        if(a[i] == item)
            return i;
    }
    return n;
}