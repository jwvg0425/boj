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
#include <time.h>

using ii = std::pair<int, int>;

int board[129][129];

int count[2];

void cut(int x, int y, int n)
{
	if (n == 1)
	{
		count[board[x][y]]++;
		return;
	}

	bool oneColor = true;
	int color = board[x][y];

	for (int nx = x; nx < x + n; nx++)
	{
		for (int ny = y; ny < y + n; ny++)
		{
			if (board[nx][ny] != color)
				oneColor = false;
		}

		if (!oneColor)
			break;
	}

	if (oneColor)
	{
		count[board[x][y]]++;
	}
	else
	{
		cut(x, y, n / 2);
		cut(x + n / 2, y, n / 2);
		cut(x, y + n / 2, n / 2);
		cut(x + n / 2, y + n / 2, n / 2);
	}
}

int main()
{
	int n;
	scanf("%d", &n);

	for (int x = 0; x < n; x++)
	{
		for (int y = 0; y < n; y++)
		{
			scanf("%d", &board[x][y]);
		}
	}

	cut(0, 0, n);

	printf("%d\n%d", count[0], count[1]);

	return 0;
}