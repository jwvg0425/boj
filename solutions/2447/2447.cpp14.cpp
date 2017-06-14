#include<stdio.h>
#include<vector>
#include<iostream>
#include<string>
#include<algorithm>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <tuple>
#include <memory.h>

char board[6562][6562];

void draw(int x, int y, int k)
{
	if (k == 1)
	{
		board[x][y] = '*';
		return;
	}

	int nextk = k / 3;

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (i == 1 && j == 1)
			{
				for (int bx = 0; bx < nextk; bx++)
				{
					for (int by = 0; by < nextk; by++)
					{
						board[x + nextk + bx][y + nextk + by] = ' ';
					}
				}
			}
			else
			{
				draw(x + i * nextk, y + j * nextk, nextk);
			}
		}
	}
}

int main()
{
	int n;

	scanf("%d", &n);

	draw(0, 0, n);

	for (int y = 0; y < n; y++)
	{
		for (int x = 0; x < n; x++)
		{
			printf("%c", board[x][y]);
		}

		printf("\n");
	}

	return 0;
}