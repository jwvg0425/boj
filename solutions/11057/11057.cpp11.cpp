#include <stdio.h>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <stack>
#include <math.h>
#include <memory.h>
#include <queue>
#include <set>

int table[1002][10];

//길이 n, i로 시작할 때 오르막 수 개수
int solve(int n, int i)
{
	if (n == 1)
		return 1;

	if (table[n][i] != -1)
		return table[n][i];

	int& res = table[n][i];
	res = 0;

	for (int j = i; j < 10; j++)
	{
		res = (res + solve(n - 1, j)) %10007;
	}

	return res;
}

int main()
{
	int n;
	scanf("%d", &n);

	memset(table, -1, sizeof(table));

	printf("%d", solve(n + 1, 0));

	return 0;
}