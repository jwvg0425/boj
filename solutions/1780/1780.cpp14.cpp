#include<stdio.h>
#include<vector>
#include<iostream>
#include<string>
#include<algorithm>
#include <set>
#include <queue>
#include <memory.h>

int board[2188][2188];

int counts[3];

void counting(int x, int y, int n)
{
	int s = board[x][y];

	bool paper = true;

	for (int i = x; i < x + n; i++)
	{
		for (int j = y; j < y + n; j++)
		{
			if (board[i][j] != s)
			{
				paper = false;
				break;
			}
		}
	}

	if (paper)
	{
		counts[s + 1]++;
		return;
	}

	//3등분
	n /= 3;

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			counting(x + i * n, y + j * n, n);
		}
	}
}

int main()
{
	int n;
	scanf("%d", &n);

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			scanf("%d", &board[i][j]);
		}
	}

	counting(0, 0, n);

	for (int i = 0; i < 3; i++)
	{
		printf("%d\n", counts[i]);
	}

	return 0;
}