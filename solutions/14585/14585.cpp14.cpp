#include <stdio.h>
#include <string>
#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>
#include <memory.h>
#include <memory>
#include <time.h>
#include <tuple>

int candies[301][301];

long long int table[301][301];

long long int solve(int x, int y)
{
	if (x > 300 || y > 300)
		return 0;

	if (table[x][y] != -1)
		return table[x][y];

	long long int& res = table[x][y];

	res = 0;

	res += std::max(0, candies[x][y] - x - y);
	res += std::max(solve(x + 1, y), solve(x, y + 1));

	return res;
}

int main()
{
	memset(table, -1, sizeof(table));

	int n, m;
	scanf("%d %d", &n, &m);

	for (int i = 0; i < n; i++)
	{
		int x, y;
		scanf("%d %d", &x, &y);
		candies[x][y] = m;
	}

	printf("%d", solve(0, 0));

	return 0;
}