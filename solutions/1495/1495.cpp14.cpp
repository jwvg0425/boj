#include <stdio.h>
#include <algorithm>
#include <queue>
#include <iostream>
#include <bitset>

int table[101][1001];
std::vector<int> volume;

int n, s, m;

//현재 볼륨 v, k~끝번째까지 순회할 때 최대 볼륨 값. 불가능하면 -1
int solve(int k, int v)
{
	if (k == n)
		return v;

	if (table[k][v] != -2)
		return table[k][v];

	int& res = table[k][v];
	res = -1;

	if (v - volume[k] >= 0)
	{
		res = std::max(res, solve(k + 1, v - volume[k]));
	}

	if (v + volume[k] <= m)
	{
		res = std::max(res, solve(k + 1, v + volume[k]));
	}

	return res;
}

int main()
{
	scanf("%d %d %d", &n, &s, &m);

	for (int i = 0; i <= n; i++)
	{
		for (int j = 0; j <= m; j++)
		{
			table[i][j] = -2;
		}
	}

	for (int i = 0; i < n; i++)
	{
		int v;
		scanf("%d", &v);
		volume.push_back(v);
	}

	printf("%d", solve(0, s));

	return 0;
}