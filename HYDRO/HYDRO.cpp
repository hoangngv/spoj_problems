// HYDRO.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;

int getMax(int begin, int end)
{
	if (begin >= end) return end;
	return begin;
}

int getMaxValue(int arr[], int n)
{
	int max = arr[0];
	for (int i = 1; i < n; i++)
	{
		if (arr[i] > max)
		{
			max = arr[i];
		}
	}
	return max;
}


int main()
{
	int n_test; // 1<=T<=20
	int n_wall[20];
	int w_height[20][10000];
	int max[20], max_index[20];
	int water_quantity[20] = { 0 };

	// input
	cin >> n_test;
	for (int i = 0; i < n_test; i++)
	{
		cin >> n_wall[i];
		for (int j = 0; j < n_wall[i]; j++)
		{
			cin >> w_height[i][j];
		}
	}
	
	// get highest wall and its index
	for (int i = 0; i < n_test; i++)
	{
		max[i] = w_height[i][0];
		max_index[i] = 0;
		for (int j = 1; j < n_wall[i]; j++)
		{
			if (w_height[i][j] > max[i])
			{
				max[i] = w_height[i][j];
				max_index[i] = j;
			}
		}
	}
	


	//cout << max[0] << " " << max_index[0] << endl;
	//cout << max[1] << " " << max_index[1] << endl;

	// print result
	for (int i = 0; i < n_test; i++)
	{
		cout << water_quantity[i] << endl;
	}
	return 0;
}


//int main()
//{
//	int n_test; // 1<=T<=20
//	int n_wall[20];
//	int w_height[20][10000];
//	int max[20];
//	int water_quantity[20] = { 0 };
//
//	// input
//	cin >> n_test;
//	for (int i = 0; i < n_test; i++)
//	{
//		cin >> n_wall[i];
//		for (int j = 0; j < n_wall[i]; j++)
//		{
//			cin >> w_height[i][j];
//		}
//	}
//
//	// calculate water quantity
//	for (int i = 0; i < n_test; i++)
//	{
//		for (int j = 0; j < n_wall[i]; j++)
//		{
//			max[i] = getMax(w_height[i][0], w_height[i][n_wall[i] - 1]);
//			if ((max[i] - w_height[i][j]) >= 0)
//			{
//				water_quantity[i] += (max[i] - w_height[i][j]);
//			}
//		}
//	}
//
//	// print result
//	for (int i = 0; i < n_test; i++)
//	{
//		cout << water_quantity[i] << endl;
//	}
//	return 0;
//}