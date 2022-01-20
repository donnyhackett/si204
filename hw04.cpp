#include <iostream>
#include <cmath>
using namespace std;

int main ()
{
	int x,y,x1,y1;
	string str;
	char c;
	cout << "Enter two lengths in feet and inches (larger first!)" << endl;
	cin >> x >> str >> y >> str;
	cin >> x1 >> str >> y1;
	int xt = (12 * x) + y;
	int yt = (12 * x1) + y1;
	int t = xt - yt;
	int f = (t / 12);
	int i = (t % 12);
	cout << "Difference is " << f << "' " << i << "''";
	return 0;
}	
