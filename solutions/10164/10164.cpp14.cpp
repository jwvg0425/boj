#include<stdio.h>
#include<vector>
#include<iostream>
#include<string>
#include<algorithm>
#include <set>
#include <queue>
#include <memory.h>

long long int table[20][20];

long long int solve(int x, int y)
{
	if (x == 1 && y == 1)
		return 1;

	if (table[x][y] != -1)
		return table[x][y];

	long long int& res = table[x][y];
	res = 0;

	if (x > 1)
		res += solve(x - 1, y);
	
	if (y > 1)
		res += solve(x, y - 1);

	return res;
}

int main()
{
	int n, m, k;
	scanf("%d %d %d", &n, &m, &k);

	memset(table, -1, sizeof(table));

	if (k == 0)
		printf("%lld", solve(n, m));
	else
	{
		int kx = (k - 1) / m + 1;
		int ky = k % m;

		if (ky == 0)
			ky = m;

		printf("%lld", solve(kx, ky) * solve(n - kx + 1, m - ky + 1));
	}

	return 0;
}