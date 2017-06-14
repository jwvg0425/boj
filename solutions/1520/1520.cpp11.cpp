#include <stdio.h>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <stack>
#include <math.h>
#include <memory.h>
#include <queue>

int heights[501][501];
int counts[501][501];

int m, n;

int count(int x, int y)
{
	if (x == n - 1 && y == m - 1)
		return 1;

	int& res = counts[x][y];

	if (res != -1)
		return res;

	res = 0;

	if (x > 0 && heights[x - 1][y] < heights[x][y])
		res += count(x - 1, y);

	if (x < n - 1 && heights[x + 1][y] < heights[x][y])
		res += count(x + 1, y);

	if (y > 0 && heights[x][y - 1] < heights[x][y])
		res += count(x, y - 1);

	if (y < m - 1 && heights[x][y + 1] < heights[x][y])
		res += count(x, y + 1);

	return res;
}

int main()
{

	scanf("%d %d", &m, &n);

	memset(counts, -1, sizeof(counts));

	for (int y = 0; y < m; y++)
	{
		for (int x = 0; x < n; x++)
		{
			scanf("%d", &heights[x][y]);
		}
	}

	printf("%d", count(0, 0));

	return 0;
}