#include <iostream>
#include <cmath>
using namespace std;

int main ()
{
	cout << "Enter a 4-bit binary number: ";
	char c0,c1,c2,c3;
	cin >> c0 >> c1 >> c2 >> c3;
	int i0 = int(c0)%48;
	int i1 = int(c1)%48;
	int i2 = int(c2)%48;
	int i3 = int(c3)%48;
	int o0 = i0 * (2*2*2);
	int o1 = i1 * (2*2);
	int o2 = i2 * 2;
	int o3 = i3;
	int out = o0 + o1 + o2 + o3;
	cout << "In decimal " << c0 << c1 << c2 << c3 << " = " << out << endl;
	return 0;
}
