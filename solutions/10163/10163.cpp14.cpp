#include <stdio.h>
#include <algorithm>
#include <queue>
#include <iostream>
#include <bitset>
#include <memory.h>
#include <math.h>
#include <stack>
#include <map>

int main()
{
	int board[101][101];

	memset(board, -1, sizeof(board));

	int n;
	scanf("%d", &n);

	for (int i = 0; i < n; i++)
	{
		int x, y, w, h;

		scanf("%d %d %d %d", &x, &y, &w, &h);

		for (int nx = x; nx < x + w; nx++)
		{
			for (int ny = y; ny < y + h; ny++)
			{
				board[nx][ny] = i;
			}
		}
	}

	for (int i = 0; i < n; i++)
	{
		int count = 0;

		for (int x = 0; x < 101; x++)
		{
			for (int y = 0; y < 101; y++)
			{
				if (board[x][y] == i)
					count++;
			}
		}

		printf("%d\n", count);
	}

	return 0;
}