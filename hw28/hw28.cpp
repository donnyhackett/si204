#include <iostream>
#include <fstream>
using namespace std;

struct Car
{
    double Apos,Xpos,Cpos,Mpos;
    double Avel,Xvel,Cvel,Mvel;
};

int main()
{
    string file, temp;
    cin >> file;
    ifstream fin(file);
    int N;
    fin >> temp >> temp >> N;
    Car car;
    fin >> temp >> temp >> car.Apos >> temp >> car.Avel;
    fin >> temp >> temp >> car.Xpos >> temp >> car.Xvel;
    fin >> temp >> temp >> car.Cpos >> temp >> car.Cvel;
    fin >> temp >> temp >> car.Mpos >> temp >> car.Mvel;
    for(int i = 0; i < 9; i++)
    {
        cout << "hour " << i << " [A:" << car.Apos + (car.Avel * i) << "][X:" << car.Xpos + (car.Xvel * i) << "][C:" << car.Cpos + (car.Cvel * i) << "][M:" << car.Mpos + (car.Mvel * i) << "]" << endl;
    }
    return 0;
}
