#include <iostream>
#include <fstream>
using namespace std;

struct Car
{
    double Apos,Xpos,Cpos,Mpos,tpos,ypos,lpos;
    double Avel,Xvel,Cvel,Mvel,tvel,yvel,lvel;
};

int main()
{
    char char1, char2, char3, char4, char5, char6, char7;
    string file, temp;
    cin >> file;
    ifstream fin(file);
    int N;
    fin >> temp >> temp >> N;
    Car car;
    if(N == 4)
    {
        fin >> char1 >> temp >> car.Apos >> temp >> car.Avel;
        fin >> char2 >> temp >> car.Xpos >> temp >> car.Xvel;
        fin >> char3 >> temp >> car.Cpos >> temp >> car.Cvel;
        fin >> char4 >> temp >> car.Mpos >> temp >> car.Mvel;
        for(int i = 0; i < 9; i++)
        {
            cout << "hour " << i << " [" << char1 << ":" << car.Apos + (car.Avel * i) << "][" << char2 << ":" << car.Xpos + (car.Xvel * i) << "][" << char3 << ":" << car.Cpos + (car.Cvel * i) << "][" << char4 << ":" << car.Mpos + (car.Mvel * i) << "]" << endl;
        }
    }
    else
    {
        fin >> char1 >> temp >> car.Apos >> temp >> car.Avel;
        fin >> char2 >> temp >> car.Xpos >> temp >> car.Xvel;
        fin >> char3 >> temp >> car.Cpos >> temp >> car.Cvel;
        fin >> char4 >> temp >> car.Mpos >> temp >> car.Mvel;
        fin >> char5 >> temp >> car.tpos >> temp >> car.tvel;
        fin >> char6 >> temp >> car.ypos >> temp >> car.yvel;
        fin >> char7 >> temp >> car.lpos >> temp >> car.lvel;
        for(int i = 0; i < 9; i++)
        {
            cout << "hour " << i << " [" << char1 << ":" << car.Apos + (car.Avel * i) << "][" << char2 << ":" << car.Xpos + (car.Xvel * i) << "][" << char3 << ":" << car.Cpos + (car.Cvel * i) << "][" << char4 << ":" << car.Mpos + (car.Mvel * i) << "][" << char5 << ":" << car.tpos + (car.tvel * i) << "][" << char6 << ":" << car.ypos + (car.yvel * i) << "][" << char7 << ":" << car.lpos + (car.lvel * i) << "]" << endl;
        }
    }
    return 0;
}
