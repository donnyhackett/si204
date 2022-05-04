#include <iostream>
#include <fstream>
using namespace std;

struct num{
    double val;
    num* next;
};

void addBack(num*, double);
double calcVal(num*, double);
void print(num*);
void deleteAll(num*);

int main()
{
    char c;
    double d = 0;

    num* numbers = new num;
    numbers->next = NULL;
    cin >> numbers->val >> c;

    while(c != ';')
    {
        cin >> d >> c;
        addBack(numbers, d);
    }

    double y = 0;
    cin >> c >> c >> y;

    cout << calcVal(numbers, y) << endl;

    deleteAll(numbers);

    return 0;
}

void addBack(num* numbers, double d)
{
    while(numbers->next != NULL)
    {
        numbers = numbers->next;
    }
    num* temp = new num;
    temp->val = d;
    temp->next = NULL;
    numbers->next = temp;
}

double calcVal(num* numbers, double y)
{
    if(numbers == NULL)
    {
        return 0;
    }
    else
    {
        return abs(numbers->val - y) + calcVal(numbers->next, y);
    }
}

void print(num* numbers)
{
    if(numbers == NULL)
    {
        return;
    }
    else
    {
        cout << numbers->val << endl;
        print(numbers->next);
    }
}

void deleteAll(num* numbers)
{
    if(numbers == NULL)
    {
        return;
    }
    deleteAll(numbers->next);
    delete numbers;
}



