#include <stdio.h>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <stack>
#include <math.h>
#include <memory.h>
#include <queue>

std::vector<int> coins;

int table[10001];

int minCoin(int k)
{
	if (table[k] != -1)
		return table[k];

	if (k == 0)
		return 0;

	int& res = table[k];
	res = 987654321;

	for (auto c : coins)
	{
		if (c > k)
		{
			continue;
		}

		int num = 1 + minCoin(k - c);

		res = std::min(num, res);
	}

	return res;
}

int main()
{
	int n, k;

	scanf("%d %d", &n, &k);

	for (int i = 0; i < n; i++)
	{
		int coin;
		scanf("%d", &coin);
		coins.push_back(coin);
	}

	memset(table, -1, sizeof(table));
	printf("%d", minCoin(k) == 987654321 ? -1 : minCoin(k));
}