#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <string>
#include <memory.h>
#include <map>
#include <vector>
#include <set>
#include <queue>
#include <stack>
#include <math.h>
#include <deque>

int edges[101][101];

int n, m;

int table[101];

int getCount(int i)
{
	if (i == n)
		return 1;

	if (table[i] != -1)
		return table[i];

	int& count = table[i];
	count = 0;

	for (int j = 1; j <= n; j++)
	{
		if (edges[i][j] != 0)
		{
			count += edges[i][j] * getCount(j);
		}
	}

	return count;
}

bool isMid[101] = { false, };

int main()
{
	memset(table, -1, sizeof(table));
	scanf("%d %d", &n, &m);

	for (int i = 0; i < m; i++)
	{
		int x, y, k;

		scanf("%d %d %d", &x, &y, &k);

		edges[y][x] = k;

		isMid[x] = true;
	}

	for (int i = 1; i <= n; i++)
	{
		if (isMid[i])
			continue;

		printf("%d %d\n", i, getCount(i));
	}

	return 0;
}