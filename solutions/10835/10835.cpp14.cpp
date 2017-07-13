#include <stdio.h>
#include <string>
#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>
#include <memory.h>
#include <memory>
#include <time.h>
#include <tuple>

std::vector<int> a;
std::vector<int> b;

int table[2001][2001];

int solve(int l, int r)
{
	if (l == a.size() || r == b.size())
		return 0;

	if (table[l][r] != -1)
		return table[l][r];

	int& res = table[l][r];

	res = std::max(solve(l + 1, r), solve(l + 1, r + 1));

	if (a[l] > b[r])
		res = std::max(res, b[r] + solve(l, r + 1));

	return res;
}

int main()
{
	memset(table, -1, sizeof(table));

	int n;
	scanf("%d", &n);

	for (int i = 0; i < n; i++)
	{
		int k;
		scanf("%d", &k);
		a.push_back(k);
	}

	for (int j = 0; j < n; j++)
	{
		int k;
		scanf("%d", &k);
		b.push_back(k);
	}

	printf("%d", solve(0, 0));

	return 0;
}