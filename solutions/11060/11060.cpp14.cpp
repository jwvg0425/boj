#include <stdio.h>
#include <algorithm>
#include <vector>
#include <iostream>
#include <string>
#include <math.h>
#include <memory.h>
#include <queue>
#include <tuple>
#include <map>
#include <functional>
#include <stack>

int table[1001];
int jump[1001];
int n;

int solve(int k)
{
	if (k >= n)
		return 1001;

	if (k == n - 1)
		return 0;

	if (table[k] != -1)
		return table[k];

	int& res = table[k];

	res = 1001;

	for (int i = 1; i <= jump[k]; i++)
	{
		res = std::min(1 + solve(k + i), res);
	}

	return res;
}

int main()
{
	scanf("%d", &n);

	memset(table, -1, sizeof(table));

	for (int i = 0; i < n; i++)
	{
		scanf("%d", &jump[i]);
	}

	printf("%d", solve(0) == 1001 ? -1 : solve(0));


	return 0;
}