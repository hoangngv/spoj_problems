// TOANDFRO.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;

int main()
{
	char matrix[200][20];
	int col;
	string inp;
	while (true)
	{
		cin >> col;
		if (col == 0) break;
		cin >> inp;
		int row = inp.length() / col;
		int index = 0;
		//return 0;
		for (int i = 0; i < row; i++)
		{
			if (i % 2 == 0)
			{
				for (int j = 0; j < col; j++)
				{
					matrix[i][j] = inp[index];
					index++;
				}
			}
			else
			{
				for (int j = col - 1; j >= 0; j--)
				{
					matrix[i][j] = inp[index];
					index++;
				}
			}
		}
		for (int j = 0; j < col; j++)
		{
			for (int i = 0; i < row; i++)
			{
				cout << matrix[i][j];
			}
		}
		cout << endl;
	}
	//cin >> col >> inp;
	
	return 0;
}
