#include <stdio.h>
#include <memory.h>
#include <vector>
#include <algorithm>
#include <string>
#include <iostream>
#include <queue>

int value[1001];
int table[1001];

int solve(int n)
{
	if (n == 0)
		return 0;

	if (n == 1)
		return value[1];

	if (table[n] != -1)
		return table[n];

	int& res = table[n];
	res = 0;

	for (int i = 1; i <= n; i++)
	{
		res = std::max(res, value[i] + solve(n - i));
	}

	return res;
}

int main()
{
	int n;
	scanf("%d", &n);

	for (int i = 0; i < n; i++)
	{
		scanf("%d", &value[i+1]);
	}

	memset(table, -1, sizeof(table));

	printf("%d", solve(n));

	return 0;
}