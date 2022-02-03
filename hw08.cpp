#include <iostream>
using namespace std;

int main()
{
	char temp;
	int cnt = 1;
	int prev;
	int next;
	cin >> prev >> temp;
	while (temp != '=')
	{
		cin >> next >> temp;
		prev = prev * next;
		cnt++;
	}
	cout << "The product of the " << cnt << " numbers entered is " << prev << endl;
	return 0;
}
