// QKP.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;

const int Q = 0; // hau
const int K = 1; // ma
const int P = 2; // tot
const int safe = 3;
const int unsafe = 4;

int ROW, COL;
int board[1000][1000]; // n: hang, m: cot

int K_direct_row[8] = { -1, -2, 1, 2, -2, -1, 2, 1 }; // ma co the di 8 huong
int K_direct_col[8] = { 2, 1, 2, 1, -1, -2, -1, -2 };

int K_count_unsafe(int row, int col)
{
	int n_unsafe = 0;
	for (int i = 0; i < 8; i++)
	{
		int r = row + K_direct_row[i];
		int c = col + K_direct_col[i];
		if (r >= 0 && r < ROW && c >= 0 && c < COL) // kiem tra dieu kien hang, cot de duyet
		{
			// safe -> unsafe
			if (board[r][c] == safe)
			{
				board[r][c] = unsafe;
				n_unsafe++;
			}
		}
	}
	return n_unsafe;
}

int Q_direct_row[8] = { 0, 0, 1, 1, 1, -1, -1, -1 }; // hau co the di 8 huong
int Q_direct_col[8] = { 1, -1, -1, 0, 1, -1, 0, 1 };

int sum_safe = 0;

void Q_count_unsafe(int row, int col, int direct_index)
{
	int r = row + Q_direct_row[direct_index];
	int c = col + Q_direct_col[direct_index];
	if (r >= 0 && r < ROW && c >= 0 && c < COL)
	{
		// safe -> unsafe
		if (board[r][c] == safe)
		{
			board[r][c] = unsafe;
			sum_safe--;
			Q_count_unsafe(r, c, direct_index);
		}
		else if (board[r][c] == unsafe)
		{
			Q_count_unsafe(r, c, direct_index);
		}
	}
}

int main()
{
	//ios::sync_with_stdio(false);
	int n_test = 0;
	while (true)
	{
		cin >> ROW >> COL;
		if (ROW == 0 && COL == 0) break;
		n_test++;
		sum_safe = ROW * COL; // tong so o safe ban dau

		// khoi tao tat ca o trang thai safe
		for (int i = 0; i < ROW; i++)
		{
			for (int j = 0; j < COL; j++)
			{
				board[i][j] = safe;
			}
		}

		int saveX[2][100], saveY[2][100];
		int pos_row, pos_col;
		int num_QKP[3];

		// nhap vao so luong QKP va vi tri 
		for (int i = 0; i < 3; i++)
		{
			cin >> num_QKP[i];
			for (int j = 0; j < num_QKP[i]; j++)
			{
				cin >> pos_row >> pos_col; // toa do 
				board[pos_row-1][pos_col-1] = i; // i=0 la hau, i=1 la ma, i=2 la tot
				if (i != 2) // i khong phai tot, i la hau & ma thi luu lai toa do
				{
					saveX[i][j] = pos_row-1;
					saveY[i][j] = pos_col-1;
				}
			}
		}

		// cap nhat lai so luong o safe
		sum_safe = sum_safe - (num_QKP[Q] + num_QKP[K] + num_QKP[P]); // ban chat la num_QKP[0]+num_QKP[1]+num_QKP[2]
		
		// duyet K (ma)
		for (int i = 0; i < num_QKP[K]; i++)
		{
			sum_safe -= K_count_unsafe(saveX[K][i], saveY[K][i]);
		}
		
		// duyet Q (hau)
		for (int i = 0; i < num_QKP[Q]; i++)
		{
			for (int j = 0; j < 8; j++)
			{
				Q_count_unsafe(saveX[Q][i], saveY[Q][i], j);
			}
		}

		// in ket qua
		cout << "Board " << n_test << " has " << sum_safe << " safe squares." << endl;
	}
	return 0;
}
