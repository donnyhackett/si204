#include <iostream>
#include <fstream>
using namespace std;

struct person{
    string name;
    int ID;
};

void sortPeople(person*, int);
bool before(int, int);
void printPeople(person*, int);

int main()
{
    string file;
    cin >> file;
    ifstream fin(file);

    if(!fin)
    {
        cout << "file not found" << endl;
        return 0;
    }

    char temp;
    fin >> temp >> temp;

    int N;
    fin >> N;

    person* people = new person[N];
    for(int i = 0; i < N; i++)
    {
        fin >> people[i].name >> people[i].ID;
    }

    sortPeople(people, N);

    printPeople(people, N);

    delete[] people;
    return 0;
}

void sortPeople(person* people, int N)
{
    for(int i = N - 1; i > 0; i--)
    {
        for(int index = N - 1; index > 0; index--)
        {
            if(before(people[index].ID, people[index-1].ID))
            {
                person temp = people[index];
                people[index] = people[index-1];
                people[index-1] = temp;
            }
        }
    }
}

bool before(int i, int j)
{
    return i > j;
}

void printPeople(person* people, int N)
{
    for(int i = 0; i < N; i++)
    {
        cout << people[i].name << " " << people[i].ID << endl;
    }
}
