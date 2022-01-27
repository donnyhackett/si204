#include <iostream>
#include <cmath>
using namespace std;

int main ()
{
	cout << "Enter a number between 0 and 15: ";
	int x;
	cin >> x;
	int b0,b1,b2,b3;
	int tmp;
	b3 = x/8;
	tmp = x-(8*b3);
	b2 = tmp/4;
	tmp = tmp-(4*b2);
	b1 = tmp/2;
	tmp = tmp-(2*b1);
	b0 = tmp/1;
	cout << x << " in binary is " << b3 << b2 << b1 << b0 << endl;
	return 0;
}
