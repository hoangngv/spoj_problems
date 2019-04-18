// PTIT121E_NguyenToHoaHoc.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main()
{
	string s;
	int len = s.length(), sum = 0;
	stack<int> st;
	cin >> s;
	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] == '(')
		{
			st.push(0);
		}
		else if (s[i] == ')')
		{
			int tmp_val = 0;
			while (!st.empty() && st.top() != 0)
			{
				tmp_val += st.top();
				st.pop();
			}
			if (!st.empty() && st.top() == 0)
			{
				st.pop();
				st.push(tmp_val);
			}
		}
		else if (s[i] >= '2' && s[i] <= '9')
		{
			int num = s[i] - '0';
			int tmp_val = 0;
			if (!st.empty())
			{
				tmp_val = st.top();
				st.pop();
				tmp_val *= num;
				st.push(tmp_val);
			}
			//st.push(tmp_val);
		}
		else if (s[i] == 'C')
		{
			st.push(12);
		}
		else if (s[i] == 'H')
		{
			st.push(1);
		}
		else if (s[i] == 'O')
		{
			st.push(16);
		}
	}
	while (!st.empty())
	{
		sum += st.top();
		st.pop();
	}
	cout << sum << endl;
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
