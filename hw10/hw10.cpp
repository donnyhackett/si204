#include <iostream>
#include <fstream>
using namespace std;

int main()
{
	ifstream fin("input.txt");
	string temp;
	string name;
	string avgs;
	double amt1;
	double amt2;
	double amt3;
	fin >> temp >> temp >> temp >> temp;
	while(fin >> name >> amt1 >> amt2 >> amt3)
	{
		cout << name << " " << ((amt1*0.2) + (amt2*0.2) + (amt3*0.6)) << endl;
	}
	return 0;
}
			
		
