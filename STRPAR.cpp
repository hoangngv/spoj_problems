#include <iostream>
using namespace std;
int stack[1000], top; // Stack dong vai tro la duong ben canh.
void Init()
{
	top = -1;
}
int pop() {
	int data;
	data = stack[top];
	top--;
	return data;
}
int push(int data) {
	top++;
	stack[top] = data;
	return data;
}
int main()
{
	//freopen ("input.txt", "r", stdin);
	int N, A[1000], i, tmp, kt; // Mang A[] de luu vi tri cac xe o dau vao, kt la bien tam de xem co xep duoc xe khng, neu kt = 1 thi khong the sap xep duoc xe
	cin >> N;
	while (N != 0)
	{
		kt = -1;
		for (i = 0; i < N; i++)
			cin >> A[i];
		Init();
		push(N + 1); // Coi trong nga re (Stack) da co san 1 xe co so thu tu la N + 1
		i = 0; // Xet tu vi tri 0;
		tmp = 0; // Coi nhu da co mot xe co so thu tu la 0 o dau ra
		while (i != N) // Khi van con xe chua duoc sap xep
		{
			if (A[i] == tmp + 1) // Vi du tmp = 0, A[i] = 1 thi xep xe A[i] vao dau ra luon
			{
				tmp = A[i];
				i++;
			}
			else if (stack[top] == tmp + 1) // Neu xe o dau nga re cos gia tri = tmp + 1?
				tmp = pop();
			else if (A[i] < stack[top])
			{
				push(A[i]);
				i++;
			}
			else
			{
				kt = 1;
				break;
			}
		}
		if (kt == 1)
			cout << "no" << endl;
		else
			cout << "yes" << endl;
		cin >> N;
	}
	return 0;
}
