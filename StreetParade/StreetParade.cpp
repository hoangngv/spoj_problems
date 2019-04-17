#include <iostream>
#include <stack>

using namespace std;

const int MAX = 1000;

int order[MAX]; // initialized positions
int check = true;
stack<int> s;

void printStack(stack<int> s)
{
	cout << "Current stack: ";
	while (!s.empty())
	{
		cout << s.top() << " ";
		s.pop();
	}
	cout << endl;
}

int main()
{
	int n = 0;
	cin >> n;
	char c;
	int index = 0;

	for (int i = 0; i <= n; i++)
	{
		cin >> order[i];
		if (order[i] == 0) break;
	}
	
	//check = true;
	int start = 1;

	for (int i = 0; i < n; i++)
	{
		while (!s.empty() && s.top() == start)
		{
			s.pop();
			start++;
		}

		if (order[i] == start) start++;
		else if (!s.empty() && s.top() < order[i]) // nếu nhỏ hơn mà đẩy vào stack thì sau sẽ ko ra được order thỏa mãn
		{
			check = false;
			break;
		}
		else {
			s.push(order[i]);
		}
	}
	//printStack(s);
	if (check) cout << "yes" << endl;
	else cout << "no" << endl;

	return 0;
}