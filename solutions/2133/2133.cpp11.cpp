#include <stdio.h>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <stack>
#include <math.h>
#include <memory.h>
#include <queue>


int table[31];

long long int solve(int n)
{
	if (n == 0)
		return 1;

	if (n == 1)
		return 0;

	if (n == 2)
		return 3;

	int& res = table[n];

	if (res != -1)
		return res;

	res = solve(n - 2) * 3;

	for (int i = 4; i <= n; i+=2)
	{
		res += solve(n - i) * 2;
	}

	return res;
}

int main()
{
	int n;

	scanf("%d", &n);

	memset(table, -1, sizeof(table));

	printf("%lld", solve(n));

	return 0;
}