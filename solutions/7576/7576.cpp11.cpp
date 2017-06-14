#include <stdio.h>
#include <memory.h>
#include <vector>
#include <algorithm>
#include <string>
#include <iostream>
#include <queue>

#define X first
#define Y second

int tomato[1001][1001];

int main()
{
	int n, m;

	std::queue<std::pair<int, int>> q;

	scanf("%d %d", &m, &n);

	for (int y = 0; y < n; y++)
	{
		for (int x = 0; x < m; x++)
		{
			scanf("%d", &tomato[x][y]);

			if (tomato[x][y] == 1)
				q.emplace(x, y);
		}
	}

	while (!q.empty())
	{
		auto top = q.front();
		q.pop();

		if (top.X > 0 && tomato[top.X - 1][top.Y] == 0)
		{
			tomato[top.X - 1][top.Y] = tomato[top.X][top.Y] + 1;
			q.emplace(top.X - 1, top.Y);
		}

		if (top.X < m - 1 && tomato[top.X + 1][top.Y] == 0)
		{
			tomato[top.X + 1][top.Y] = tomato[top.X][top.Y] + 1;
			q.emplace(top.X + 1, top.Y);
		}

		if (top.Y > 0 && tomato[top.X][top.Y - 1] == 0)
		{
			tomato[top.X][top.Y - 1] = tomato[top.X][top.Y] + 1;
			q.emplace(top.X, top.Y - 1);
		}

		if (top.Y < n - 1 && tomato[top.X][top.Y + 1] == 0)
		{
			tomato[top.X][top.Y + 1] = tomato[top.X][top.Y] + 1;
			q.emplace(top.X, top.Y + 1);
		}
	}

	int day = 0;

	for (int x = 0; x < m; x++)
	{
		for (int y = 0; y < n; y++)
		{
			if (tomato[x][y] == 0)
			{
				printf("-1");
				return 0;
			}

			day = std::max(day, tomato[x][y] - 1);
		}
	}

	printf("%d", day);

	return 0;
}