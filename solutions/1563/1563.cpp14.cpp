#include <stdio.h>
#include <vector>
#include <algorithm>
#include <tuple>
#include <map>
#include <set>
#include <iostream>
#include <string>
#include <stack>
#include <queue>
#include <memory.h>

int table[1001][3][4];

int solve(int remain, int late, int out)
{
	if (remain == 0)
		return 1;

	if (table[remain][late][out] != -1)
		return table[remain][late][out];

	int& res = table[remain][late][out];

	res = solve(remain - 1, late, 0);

	//지각
	if (late == 0)
	{
		res = (res + solve(remain - 1, late + 1, 0)) % 1000000;
	}

	if (out < 2)
	{
		res = (res + solve(remain - 1, late, out + 1)) % 1000000;
	}

	return res;
}

int main()
{

	memset(table, -1, sizeof(table));
	int n;

	scanf("%d", &n);

	printf("%d", solve(n, 0, 0));

	return 0;
}