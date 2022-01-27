#include <iostream>
#include <cmath>
using namespace std;

int main ()
{
	cout << "Permissions: ";
	char i0,i1,i2;
	cin >> i0 >> i1 >> i2;
	int p0 = int(i0)%48;
	int p1 = int(i1)%48;
	int p2 = int(i2)%48;
	int first0,first1,first2;
	int tmp;
	first2 = p0/4;
	tmp = p0-(4*first2);
	first1 = tmp/2;
	tmp = tmp-(2*first1);
	first0 = tmp/1;
	int second0,second1,second2;
	second2 = p1/4;
	tmp = p1-(4*second2);
	second1 = tmp/2;
	tmp = tmp-(2*second1);
	second0 = tmp/1;
	int third0,third1,third2;
	third2 = p2/4;
	tmp = p2-(4*third2);
	third1 = tmp/2;
	tmp = tmp-(2*third1);
	third0 = tmp/1;

	cout << "\n" << "User:" << "\n" << "read" << "    " << first2 << endl;
	cout << "write" << "   " << first1 << endl;
	cout << "execute" << " " << first0 << endl;
	cout << "\n";
	cout << "Group:" << endl;
	cout << "read" << "    " << second2 << endl;
	cout << "write" << "   " << second1 << endl;
	cout << "execute" << " " << second0 << endl;
	cout << "\n";
	cout << "Other:" << endl;
	cout << "read" << "    " << third2 << endl;
	cout << "write" << "   " << third1 << endl;
	cout << "execute" << " " << third0 << endl;

	return 0;
}
