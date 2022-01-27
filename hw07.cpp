#include <iostream>
using namespace std;

int main()
{
	string name;
	double sqpr;
	int flag;
	char conduct;
	char mp;
	char pe;
	char prt;
	char temp;
	cin >> temp >> name >> sqpr >> flag >> conduct >> mp >> pe >> prt>> temp;
	if((sqpr >= 3.4)&&(flag == 0))
	{
		if((conduct == 'A')&&(mp == 'A')&&(pe <= 'B')&&(prt <= 'B'))
		{
			cout << "Midshipman " << name << ": Superintendent's List" << endl;
		}
		else/* if((conduct == 'B')&&(mp == 'B')&&(pe <= 'C')&&(prt <= 'C'))*/
		{
			cout << "Midshipman " << name << ": Dean's List" << endl;
		}
	}
	else
	{
		cout << "Midshipman " << name << ": NQ (not qualified)" << endl;
	}
	return 0;
}

