#include <iostream>
#include <cmath>

using namespace std;

int main ()
{
	double x, y, z;
	cout << "Enter length x: ";
	cin >> x;
	cout << "Enter length y (<" << x << "): ";
	cin >> y;
	double AC = sqrt((x*x)-(y*y));
	cout << "Enter length z (<" << AC << "): ";
	cin >> z;
	double DC = (AC - z);
	double BD = sqrt((DC*DC)+(y*y));
	cout << "Length of BD is " << BD << endl;
	return 0;
}
