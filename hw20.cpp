#include <iostream>

using namespace std;

int main()
{
    int n;
    string s, temp;
    cout << "Number of words: ";
    cin >> n;
    cout << "Sentence: ";


    for(int i = 0; i < n; i++)
    {
        cin >> temp;
        if(i > 0)
            s += " ";
        s += temp;
    }
    int b = s.length() - 1;

    for(int i = 0; i <= b; i++)
        cout << s[i];
    cout << "? ";

    int e = 0;

    for(int i = n; i > 0; i--)
    {
        for(int j = b; j > e; j--)
        {
            if(s[j] == ' ')
            {
                e = b;
                b = j + 1;
            }
            else if(j == 1)
            {
                e = b;
                b = 0;
            }
        }
        for(int j = b ; j <= e; j++)
        {
            cout << s[j];
        }
        if(i > 1)
            cout << " ";
        b = b - 2;
        e = 0;
    }
    cout << "!" << endl;
    
    return 0;
}