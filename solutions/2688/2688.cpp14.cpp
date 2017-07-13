#include <stdio.h>
#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <tuple>
#include <memory.h>

long long int table[65][10];

long long int solve(int n, int d)
{
	if (n == 0)
		return 1;

	if (table[n][d] != -1)
		return table[n][d];

	long long int& res = table[n][d];

	res = 0;

	for (int nd = d; nd < 10; nd++)
		res += solve(n - 1, nd);

	return res;
}

int main()
{
	memset(table, -1, sizeof(table));

	int t;
	scanf("%d", &t);

	for (int i = 0; i < t; i++)
	{
		int n;
		scanf("%d", &n);

		printf("%lld\n", solve(n, 0));
	}

	return 0;
}