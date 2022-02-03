#include <iostream>
using namespace std;

int main()
{
	cout << "Enter a fraction addition problem: ";
	int n1, n2, d1, d2;
	char temp;
	cin >> n1 >> temp >> d1 >> temp >> n2 >> temp >> d2;
	int nf = (n1*d2) + (n2*d1);
	int df = d1*d2;
	int a, b, c;
	if (nf > df)
	{
		a = nf;
		b = df;
	}
	else
	{
		a = df;
		b = nf;
	}	
	while ((a % b) != 0)
	{
		c = a % b;
		a = b;
		b = c;
	}
	cout << n1 << "/" << d1 << " + " << n2 << "/" << d2 << " = " << nf/b << "/" << df/b << endl;
	return 0;
}
