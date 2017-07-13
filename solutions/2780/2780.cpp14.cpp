#include <stdio.h>
#include <vector>
#include <algorithm>
#include <string>
#include <iostream>
#include <memory.h>
#include <stack>
#include <queue>
#include <map>
#include <set>
#define MOD 1234567

using ii = std::pair<int, int>;

std::vector<int> adj[] =
{
	{ 7 },
	{ 2, 4 },
	{ 1, 3, 5 },
	{ 2, 6 },
	{ 1, 5, 7 },
	{ 2, 4, 6 , 8 },
	{ 3, 5, 9 },
	{ 0, 4, 8 },
	{ 5, 7, 9 },
	{ 6, 8 }
};

int table[1001][10];

int count(int n, int k)
{
	if (n == 0)
		return 1;

	if (table[n][k] != -1)
		return table[n][k];

	int& res = table[n][k];
	res = 0;

	for (auto& a : adj[k])
		res = (res + count(n - 1, a)) % MOD;

	return res;
}

void solve()
{
	int n;
	scanf("%d", &n);

	int ans = 0;

	for (int i = 0; i < 10; i++)
		ans = (ans + count(n - 1, i)) % MOD;

	printf("%d\n", ans);
}

int main()
{
	memset(table, -1, sizeof(table));

	int t;
	scanf("%d", &t);

	for (int i = 0; i < t; i++)
		solve();

	return 0;
}