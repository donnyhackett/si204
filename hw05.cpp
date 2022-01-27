#include <iostream>
#include <cmath>
using namespace std;

int main ()
{
	cout << "Input a 3-letter word in lowercase letters: ";
	char c0,c1,c2;
	cin >> c0 >> c1 >> c2;
	cout << "With leading letter capitalized this is" << "   : " << char(c0-32) << c1 << c2 << endl;
	return 0;
}
