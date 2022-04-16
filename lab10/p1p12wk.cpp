#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    string temp;
    cin >> temp;
    int* a = new int[n];
    for(int i = 0;, i < n; i++)
    {
        cin >> a[i];
    }
    cin >> temp;
    int comp;
    cin >> comp;
    cout << "[ ";
    for(int i = 0; i < n; i++)
    {
        if(temp == ">")
        {
            if(a[i] > comp)
            {
                cout << a[i] << " ";
            }
        }
        else if(temp == "<")
        {
            if(a[i] < comp)
            {
                cout << a[i] << " ";
            }
        }
    }
    cout << "]" << endl;

    return 0;
}