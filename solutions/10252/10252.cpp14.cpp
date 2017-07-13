#include <stdio.h>
#include <vector>
#include <algorithm>
#include <string>
#include <iostream>
#include <memory.h>
#include <stack>
#include <queue>
#include <map>
#include <set>

using ii = std::pair<int, int>;

void print(int x, int y)
{
	printf("(%d,%d)\n", x, y);
}

void solve()
{
	int m, n;

	scanf("%d %d", &m, &n);

	printf("1\n");

	for (int y = 0; y < n; y++)
	{
		print(0, y);
	}

	for (int x = 1; x < m; x++)
	{
		print(x, n - 1);
	}

	int nowX = m - 1, nowY = n - 2;
	int dx = -1;

	while (nowY >= 0)
	{
		print(nowX, nowY);
		if (nowX + dx == 0 || nowX + dx == m)
		{
			nowY--;
			dx = -dx;
		}
		else
		{
			nowX += dx;
		}
	}
}

int main()
{
	int t;
	scanf("%d", &t);
	for (int i = 0; i < t; i++)
		solve();

	return 0;
}