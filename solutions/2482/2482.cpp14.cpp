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
#define MOD  1000000003

int table[1001][1001];

//n개짜리 색상환에서 인접한 거 선택 안 하고 k개 고르는 경우의 수
int solve(int n, int k)
{
	if (n <= 0)
	{
		if (k > 0)
			return 0;
		else
			return 1;
	}

	if (k == 0)
		return 1;

	if (table[n][k] != -1)
		return table[n][k];

	int& res = table[n][k];
	res = (solve(n - 2, k - 1) + solve(n - 1, k)) % MOD;

	return res;
}

int main()
{
	memset(table, -1, sizeof(table));
	int n, k;

	scanf("%d %d", &n, &k);

	printf("%d", (solve(n - 3, k - 1) + solve(n - 1, k)) % MOD);

	return 0;
}