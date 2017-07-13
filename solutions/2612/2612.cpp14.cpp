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

std::string a;
std::string b;

int table[1001][1001];
std::pair<int, int> start[1001][1001];

int solve(int n, int m)
{
	if (n == 0 && m == 0)
	{
		start[0][0] = std::make_pair(0, 0);
		if (a[n] == b[m])
			return 3;
		else
			return -2;
	}

	if (table[n][m] != -1)
		return table[n][m];

	int& res = table[n][m];
	res = 0;
	int add;

	if (a[n] == b[m])
	{
		add = 3;
		res = 3;
		start[n][m] = std::make_pair(n, m);
	}
	else
	{
		add = -2;
	}

	if (n > 0 && m > 0 && solve(n - 1, m - 1) + add > res)
	{
		res = solve(n - 1, m - 1) + add;
		start[n][m] = start[n - 1][m - 1];
	}

	if (n > 0 && solve(n - 1, m) - 2 > res)
	{
		res = solve(n - 1, m) - 2;
		start[n][m] = start[n - 1][m];
	}

	if (m > 0 && solve(n, m - 1) - 2 > res)
	{
		res = solve(n, m - 1) - 2;
		start[n][m] = start[n][m - 1];
	}

	return res;
}

int main()
{
	memset(table, -1, sizeof(table));

	int n, m;

	std::cin >> n >> a >> m >> b;

	int max = 0;
	int ax, bx;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (solve(i, j) > max)
			{
				max = solve(i, j);
				ax = i;
				bx = j;
			}
		}
	}

	int astart = start[ax][bx].first;
	int bstart = start[ax][bx].second;

	printf("%d\n", max);

	std::cout << a.substr(astart, ax - astart + 1) << std::endl;
	std::cout << b.substr(bstart, bx - bstart + 1) << std::endl;


	return 0;
}