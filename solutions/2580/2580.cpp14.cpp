#include<stdio.h>
#include<vector>
#include<iostream>
#include<string>
#include<algorithm>
#include <set>
#include <queue>
#include <tuple>
#include <memory.h>

int board[9][9];
int ys[9];
int xs[9];
int sub[3][3];

void remove(int x, int y)
{
	if (board[x][y] == 0)
		return;

	xs[x] &= ~(1 << board[x][y]);
	ys[y] &= ~(1 << board[x][y]);
	sub[x / 3][y / 3] &= ~(1 << board[x][y]);

	board[x][y] = 0;
}

void assign(int x, int y, int k)
{
	board[x][y] = k;

	ys[y] |= (1 << board[x][y]);
	xs[x] |= (1 << board[x][y]);
	sub[x/3][y/3] |= (1 << board[x][y]);
}

bool fill()
{
	for (int x = 0; x < 9; x++)
	{
		for (int y = 0; y < 9; y++)
		{
			if (board[x][y] != 0)
				continue;

			int cand = xs[x] | ys[y] | sub[x/3][y/3];

			for (int i = 1; i <= 9; i++)
			{
				if ((cand & (1 << i)) != 0)
					continue;

				assign(x, y, i);

				if (fill())
					return true;

				remove(x, y);
			}

			if (board[x][y] == 0)
				return false;
		}
	}

	return true;
}

int main()
{
	for (int x = 0; x < 9; x++)
	{
		for (int y = 0; y < 9; y++)
		{
			scanf("%d", &board[x][y]);
		}
	}

	for (int x = 0; x < 9; x++)
	{
		for (int y = 0; y < 9; y++)
		{
			if (board[x][y] == 0)
				continue;

			ys[y] |= (1 << board[x][y]);
			xs[x] |= (1 << board[x][y]);
			sub[x/3][y/3] |= (1 << board[x][y]);
		}
	}

	fill();

	for (int x = 0; x < 9; x++)
	{
		for (int y = 0; y < 9; y++)
		{
			printf("%d ", board[x][y]);
		}

		printf("\n");
	}

	return 0;
}