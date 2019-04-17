// PTIT121I_LapKyTu.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;

string repeatString(string s, int repeat)
{
	string res = "";
	for (int i = 0; i < s.length(); i++)
	{
		for (int j = 0; j < repeat; j++)
		{
			res += s[i];
		}
	}
	return res;
}

int main()
{
	string inp[1000];
	int test_suites, repeat_times[1000], test[1000];
	cin >> test_suites;

	for (int i = 0; i < test_suites; i++)
	{
		cin >> test[i] >> repeat_times[i] >> inp[i];
	}
	
	for (int i = 0; i < test_suites; i++)
	{
		cout << test[i] << " " << repeatString(inp[i], repeat_times[i]) << endl;
	}
	return 0;
}

