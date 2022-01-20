#include <iostream>
using namespace std;

int main ()
{
	int int1 = 5;
	int int2 = 7;
	cout << (int2 / int1) << endl;
	cout << (int2 % int1) << endl;

	char aChar = 'a';
	cout << "Starting this line: " << aChar << '\t'
        << 'b' << '\n' << 'c' << " Ending this line." << endl;
	
	bool aTrue = true;
	bool aFalse = false;
	cout << aTrue << endl;
	cout << aFalse << endl;
	cout << (aTrue && aFalse) << endl;
	cout << (aTrue || aFalse) << endl;
	cout << !aTrue << ' ' << !aFalse << endl;

	string str1 = "A string!";
	string str2 = "Another string.";

	cout << str1+str2 << endl;
		
	return 0;
}
