// GUITIEN.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;

const float laiSuat = 0.1;

int rd(float money)
{
	if ((money - (int)money) >= 0.5) money = (int)money + 1;
	else money = (int)money;
	return money;
}

int main()
{
	int n, m;
	cin >> n >> m;
	int updateMoney = n, yearNeeded = 0;
	while (updateMoney < m)
	{
		int gainMoney = rd(updateMoney * laiSuat);
		updateMoney += gainMoney;
		//cout << updateMoney << endl;
		yearNeeded++;
	}
	cout << yearNeeded << endl;
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
