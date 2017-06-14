#include <stdio.h>
#include <memory.h>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>
#include <iostream>
#include <string>
#include <set>

int n, k;

std::vector<std::pair<int, int>> coins;
int table[10001][101];

int solve(int ni, int ki)
{
	if (ni < 0)
		return 0;

	if (ni == 0)
		return 1;

	if (ki == k)
		return 0;

	if (table[ni][ki] != -1)
		return table[ni][ki];

	int& res = table[ni][ki];
	res = 0;

	for (int i = 0; i <= coins[ki].second; i++)
	{
		res += solve(ni - i * coins[ki].first, ki + 1);
	}

	return res;
}

int main()
{
	scanf("%d %d", &n, &k);

	memset(table, -1, sizeof(table));

	for (int i = 0; i < k; i++)
	{
		int pi, ni;
		scanf("%d %d", &pi, &ni);
		coins.emplace_back(pi, ni);
	}

	printf("%d", solve(n, 0));

	return 0;
}