#include <iostream>
#include <fstream>
using namespace std;

struct person{
    string name;
    string color;
    int degree;
};

int findP(person* people, string name, int N);

int main()
{
    int N;
    cin >> N;

    char temp;

    person* people = new person[N];
    for(int i = 0; i < N; i++)
    {
        cin >> temp >> people[i].name >> people[i].color >> people[i].degree;
    }

    string cmd = "";
    string name = "";
    string sub = "";

    cin >> cmd;
    while(cmd != "quit")
    {
        cin >> name >> sub;
        int index = findP(people, name, N);
        if(cmd == "degree")
        {
            if(sub == "up")
            {
                people[index].degree++;
            }
            else
            {
                people[index].degree--;
            }
        }
        else if(cmd == "color")
        {
            people[index].color = sub;
        }
        cin >> cmd;
    }

    cout << N;
    for(int i = 0; i < N; i++)
    {
        cout << " , " << people[i].name << " " << people[i].color << " " << people[i].degree;
    }
    cout << endl;

    delete[] people;
    return 0;
}

int findP(person* people, string name, int N)
{
    for(int i = 0; i < N; i++)
    {
        if(people[i].name == name)
        {
            return i;
        }
    }
    return N;
}