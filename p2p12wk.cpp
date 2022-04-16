#include <iostream>
#include <fstream>
using namespace std;

int find(string* b, int n, string item);

int main()
{
    int n;
    string file;
    cin >> file;
    ifstream fin(file);
    string temp;
    fin >> temp >> temp;
    fin >> n;
    
    string* b = new string[n];
    for(int i = 0; i < n; i++)
    {
        fin >> b[i];
    }

    string* a = new string[n];
    for(int i = 0; i < n; i++)
    {
        fin >> a[i];
    }
    

    string combined;
    int length = 0;
    cin >> temp;
    while(temp != ".")
    {
        combined += temp + " ";
        length++;
        cin >> temp;
    }
    
    string* in = new string[length];

    int index = 0;
    for(int j = 0; j < combined.length(); j++)
    {
        if(combined[j] != ' ')
        {
            in[index] += combined[j];
        }
        else
        {
            index++;
        }
    }


    for(int i = 0; i < length; i++)
    {
        index = find(b, n, in[i]);
        if(index < n)
        {
            cout << a[index];
        }
    }
    cout << endl;
    




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