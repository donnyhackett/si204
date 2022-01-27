#include <iostream>
#include <cmath>
using namespace std;

int main ()
{
	cout << "Enter year: ";
	int year;
	cin >> year;
	if ((year % 4) == 0)
	{
		if ((year % 100) == 0)
		{
			if ((year % 400) == 0)
			{
				cout << "Is Leap Year" << endl;
			}
			else
			{
				cout << "Is Not Leap Year" << endl;
			}
		}
		else
		{
			cout << "Is Leap Year" << endl;
		}
	}
	else
	{
		cout << "Is Not Leap Year" << endl;
	}
	return 0;
}
