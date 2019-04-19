// TurboSort_.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;

int n, arr[1000005], F[1000005];

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
		F[arr[i]]++;
	}
	for (int number = 0; number <= 1000000; number++)
	{
		for (int i = 0; i < F[number]; i++)
		{
			cout << number << " ";
		}
	}
	return 0;
}