#include <stdio.h>
#include <memory.h>
#include <queue>
#include <vector>
#include <algorithm>
#include <string>
#include <iostream>
#include <tuple>
#define MOD 1000000000

int table[201][201];

int solve(int n, int k)
{
	if (k == 1)
		return 1;

	if (table[n][k] != -1)
		return table[n][k];

	int& res = table[n][k];
	res = 0;

	for (int i = 0; i <= n; i++)
	{
		res = (res + solve(n - i, k - 1)) % MOD;
	}

	return res;
}

int main()
{
	int n, k;
	scanf("%d %d", &n, &k);

	memset(table, -1, sizeof(table));

	printf("%d", solve(n, k));

	return 0;
}