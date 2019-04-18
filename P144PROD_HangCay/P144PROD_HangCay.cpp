// P144PROD_HangCay.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;

long long minHeight(long long arr[], int n)
{
	long long res = arr[0];
	for (int i = 1; i < n; i++)
	{
		if (res > arr[i]) res = arr[i];
	}
	return res;
}

long long maxHeight(long long arr[], int n)
{
	long long res = arr[0];
	for (int i = 1; i < n; i++)
	{
		if (res < arr[i])  res = arr[i];
	}
	return res;
}

int main()
{
	int n_trees; // n<=20
	long long t_height[20];
	long long t_min = 0, t_max = 0, t_equal = 0;
	bool equal = false;
	string eq = "There is a row of trees having equal height.";
	cin >> n_trees;
	for (int i = 0; i < n_trees; i++)
	{
		cin >> t_height[i];
		t_equal = t_height[0];
		if (t_equal == t_height[i])
		{
			equal = true;
		} else equal = false;
	}
	if (!equal)
	{
		t_min = minHeight(t_height, n_trees);
		t_max = maxHeight(t_height, n_trees);
		cout << t_min << " " << t_max << endl;
	}
	else {
		cout << eq << endl;
	}
	return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
