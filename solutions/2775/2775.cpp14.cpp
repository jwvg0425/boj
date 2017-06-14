#include <stdio.h>
#include <memory.h>
#include <queue>
#include <vector>
#include <algorithm>
#include <string>
#include <iostream>
#include <tuple>

int table[15][15];

int solve(int a, int b)
{
	if (a == 0)
		return b;

	if (table[a][b] != -1)
		return table[a][b];

	auto& res = table[a][b];
    res = 0;

	for (int i = 1; i <= b; i++)
		res += solve(a - 1, i);

	return res;
}

void solve()
{
	int n, k;

	scanf("%d %d", &n, &k);

	printf("%d\n", solve(n, k));
}

int main()
{
	int t;
	scanf("%d", &t);

	memset(table, -1, sizeof(table));

	for (int i = 0; i < t; i++)
	{
		solve();
	}

	return 0;
}