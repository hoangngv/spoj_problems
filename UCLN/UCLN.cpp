#include <iostream>
#include <stdlib.h>

using namespace std;

int UCLN(int a, int b)
{
	a = abs(a);
	b = abs(b);
	while (a != 0 && b != 0)
	{
		if (a > b)
		{
			a %= b;
		}
		else b %= a;
	}
	return (a+b);
}

int main()
{
	int a, b;
	cin >> a >> b;
	cout << UCLN(a, b);
	return 0;
}