#include <stdio.h>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <stack>
#include <math.h>
#include <memory.h>
#include <queue>

int val[1001][1001];
int table[1001][1001];
int n, m;

int cost(int x, int y)
{
	if (x < 0 || y < 0)
		return 0;

	if (table[x][y] != -1)
		return table[x][y];

	int& res = table[x][y];

	res = std::max(cost(x - 1, y), cost(x, y - 1)) + val[x][y];

	return res;
}

int main()
{
	scanf("%d %d", &n, &m);

	for (int x = 0; x < n; x++)
	{
		for (int y = 0; y < m; y++)
		{
			scanf("%d", &val[x][y]);
		}
	}

	memset(table, -1, sizeof(table));

	printf("%d", cost(n-1, m-1));

	return 0;
}