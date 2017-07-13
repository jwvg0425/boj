#include<stdio.h>
#include<vector>
#include<iostream>
#include<string>
#include<algorithm>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <tuple>
#include <memory.h>

int table[2][1001][1001];
std::vector<int> cards;

int count(int player, int left, int right)
{
	if (left == right)
		return player == 0 ? cards[left] : 0;

	if (table[player][left][right] != -1)
		return table[player][left][right];

	int& res = table[player][left][right];

	int next = (player + 1) % 2;
	if (player == 0)
		res = std::max(count(next, left + 1, right) + cards[left]
			, count(next, left, right - 1) + cards[right]);
	else
		res = std::min(count(next, left + 1, right)
			,count(next, left, right - 1));

	return res;
}

void solve()
{
	memset(table, -1, sizeof(table));
	cards.clear();

	int n;
	scanf("%d", &n);

	for (int i = 0; i < n; i++)
	{
		int k;
		scanf("%d", &k);
		cards.push_back(k);
	}

	printf("%d\n", count(0, 0, n - 1));
}

int main()
{
	int t;
	scanf("%d", &t);

	for (int i = 0; i < t; i++)
		solve();

	return 0;
}