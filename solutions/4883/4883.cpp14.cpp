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
#define INF (100000001)

int cost[100001][3];
int table[100001][3];

int solve(int line, int pos)
{
	if (line == 0)
	{
		if (pos == 0)
			return INF;

		if(pos == 1)
			return cost[line][pos];

		if (pos == 2)
			return cost[line][1] + cost[line][2];
	}

	if (table[line][pos] != INF)
		return table[line][pos];

	int& res = table[line][pos];

	res = solve(line - 1, pos);

	if (pos > 0)
	{
		res = std::min({ res, solve(line - 1, pos - 1), solve(line, pos - 1) });
	}

	if (pos < 2)
		res = std::min(res, solve(line - 1, pos + 1));

	res += cost[line][pos];

	return res;
}

int main()
{
	int t = 1;
	while (true)
	{
		int n;
		scanf("%d", &n);

		if (n == 0)
			break;

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				scanf("%d", &cost[i][j]);
				table[i][j] = INF;
			}
		}

		printf("%d. %d\n", t, solve(n - 1, 1));
		t++;
	}

	return 0;
}