#include <iostream>

using namespace std;

int order[1000], stack[1000], top; // initialized positions
bool check;

int stack_pop() {
	int data;
	data = stack[top];
	top--;
	return data;
}
int stack_push(int data) {
	top++;
	stack[top] = data;
	return data;
}

int main()
{
	int n;
	cin >> n;
	while (n != 0)
	{
		for (int i = 0; i < n; i++)
		{
			cin >> order[i];
		}

		top = -1;
		check = true;
		int index = 0, start = 0;
		stack_push(n + 1);

		//cout << n + 1 << endl;
		while (index != n)
		{
			if (order[index] == (start + 1))
			{
				start = order[index];
				index++;
			}
			else if (stack[top] == (start + 1))
			{
				start = stack_pop();
			}
			else if (order[index] < stack[top])
			{
				stack_push(order[index]);
				index++;
			}
			else {
				check = false;
				break;
			}
		}

		if (check) cout << "yes" << endl;
		else cout << "no" << endl;

		cin >> n;
	}
	return 0;
}


//#include <iostream>
//#include <stack>
//
//using namespace std;
//
//int order[1000]; // initialized positions
//bool check;
//stack<int> s;
//
//int main()
//{
//	int n;
//	cin >> n;
//	while (n != 0)
//	{
//		for (int i = 0; i < n; i++)
//		{
//			cin >> order[i];
//		}
//
//		check = true;
//		int index = 0, start = 0;
//		s.push(n + 1);
//		//cout << n+1 << endl;
//		while (index != n)
//		{
//			if (order[index] == start + 1)
//			{
//				start = order[index];
//				index++;
//			}
//			else if (s.top() == start + 1)
//			{
//				start = s.top();
//				s.pop();
//			}
//			else if (order[index] < s.top())
//			{
//				s.push(order[index]);
//				index++;
//			}
//			else {
//				check = false;
//				break;
//			}
//		}
//
//		if (check) cout << "yes" << endl;
//		else cout << "no" << endl;
//
//		cin >> n;
//	}
//	return 0;
//}