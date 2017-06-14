#include <stdio.h>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <stack>
#include <math.h>
#include <memory.h>
#include <queue>

int map[52][52];
int d[3] = { -1,0,1 };

void remove(int x, int y)
{
	map[x][y] = 0;

	for (int dx = 0; dx < 3; dx++)
	{
		for (int dy = 0; dy < 3; dy++)
		{
			int nx = x + d[dx];
			int ny = y + d[dy];

			if (map[nx][ny] == 1)
				remove(nx, ny);
		}
	}
}

bool solve()
{
	int w, h;

	scanf("%d %d", &w, &h);

	if (w == 0 && h == 0)
		return false;

	for (int y = 1; y <= h; y++)
	{
		for (int x = 1; x <= w; x++)
		{
			scanf("%d", &map[x][y]);
		}
	}

	int count = 0;

	for (int x = 1; x <= w; x++)
	{
		for (int y = 1; y <= h; y++)
		{
			if (map[x][y] == 0)
				continue;

			remove(x, y);
			count++;
		}
	}

	printf("%d\n", count);

	return true;
}

int main()
{
	while (solve());

	return 0;
}