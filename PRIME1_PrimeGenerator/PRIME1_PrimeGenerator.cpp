// PRIME1_PrimeGenerator.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;

bool isPrime(int a)
{
	if (a == 0 || a == 1) return false;
	if (a == 2) return true;
	for (int i = 2; i*i <= a; i++)
	{
		if (a % i == 0) return false;
	}
	return true;
}


int main()
{
	int m, n, n_test;
	cin >> n_test;
	for (int i = 0; i < n_test; i++)
	{
		cin >> m >> n;
		for (int j = m; j <= n; j++)
		{
			if (isPrime(j)) cout << j << endl;
		}
		cout << endl;
	}
	return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu
