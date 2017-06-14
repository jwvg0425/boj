#include<stdio.h>
#include<memory.h>
#include <queue>
#include <vector>
#include <algorithm>
#include <string>
#include <iostream>

int main()
{
	int t;
	scanf("%d", &t);

	for (int i = 0; i < t; i++)
	{
		int m, n;
		scanf("%d %d", &m, &n);

		int board[101][101];
		int count = 0;

		for (int y = m-1; y >= 0; y--)
			for (int x = 0; x < n; x++)
				scanf("%d", &board[x][y]);

		for (int x = 0; x < n; x++)
		{
			int line = 0;
			for (int y = 0; y < m; y++)
			{
				if (board[x][y] == 1)
				{
					count += y - line;
					line++;
				}
			}
		}

		printf("%d\n", count);
	}

	return 0;
}