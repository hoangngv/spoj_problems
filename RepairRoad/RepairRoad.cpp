// RepairRoad.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

using namespace std;

int maxLen = 0;
vector<int> v;

void countContinuous(int arr[], int n)
{
	int len = 0;
	arr[n] = 0;
	for (int i = 0; i <= n; i++)
	{
		//cout << arr[i] << endl;
		if (arr[i] == 1) len++;
		else if (arr[i] == 0)
		{
			v.push_back(len);
			if (len > maxLen)
			{
				maxLen = len;
			}
			len = 0;
		}
	}
	//return maxLen;
}

// tinh so luong bit 0 xuat hien trong mang
int countZero(int arr[], int n)
{
	int res = 0;
	for (int i = 0; i < n; i++)
	{
		if (arr[i] == 0) res++;
	}
	return res;
}

int main()
{
	int arr[10005], n_test;
	cin >> n_test;
	for (int it = 0; it < n_test; it++)
	{
		int n, unit;
		cin >> n >> unit;
		for (int i = 0; i < n; i++)
		{
			cin >> arr[i];
		}

		// reset 
		v.clear();
		maxLen = 0;

		countContinuous(arr, n);
		int F[10005];
		F[0] = v[0];
		for (int i = 1; i < v.size(); i++)
		{
			F[i] = F[i - 1] + v[i];
		}
		int start = 0, end = 0, finalMaxLen = 0;

		if (countZero(arr, n) <= unit) {
			cout << n << endl;
			continue;
		}

		for (int i = 0; i < (n - unit); i++)
		{
			start = i;
			end = i + unit;
			if (i == 0)
			{
				finalMaxLen = F[end] + unit;
			}
			else {
				finalMaxLen = F[end] - F[start - 1] + unit;
			}

			if (finalMaxLen > maxLen)
			{
				maxLen = finalMaxLen;
			}
		}
		cout << maxLen << endl;
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
