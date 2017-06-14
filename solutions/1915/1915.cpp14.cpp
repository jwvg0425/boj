#include<stdio.h>
#include<memory.h>
#include <queue>
#include <vector>
#include <algorithm>
#include <string>
#include <iostream>

std::vector<std::string> map;
int table[1001][1001];

int solve(int x, int y)
{
	if (x < 0 || y < 0)
		return 0;

	if (table[x][y] != -1)
		return table[x][y];

	int& res = table[x][y];

	if (map[y][x] - '0' == 0)
	{
		res = 0;
	}
	else
	{
		res = 1 + std::min({ solve(x - 1, y), solve(x, y - 1), solve(x - 1, y - 1) });
	}

	return res;
}

int main()
{
	memset(table, -1, sizeof(table));
	int n, m;
	scanf("%d %d", &n, &m);

	for (int i = 0; i < n; i++)
	{
		std::string str;
		std::cin >> str;

		map.push_back(str);
	}

	int max = 0;

	for (int x = 0; x < m; x++)
	{
		for (int y = 0; y < n; y++)
		{
			max = std::max(max, solve(x, y));
		}
	}

	printf("%d", max*max);

	return 0;
}