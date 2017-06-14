#include <stdio.h>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <stack>
#include <memory.h>
#include <queue>
#define MAX 987654321


int n, m;
int table[10001][21];
std::vector<int> coin;

//k번째~끝번째 코인으로 c원 만드는 경우의 수
int calc(int c, int k)
{
	if (c == 0)
		return 1;

	if (k >= coin.size())
		return 0;

	if (c < 0)
		return 0;

	if (table[c][k] != -1)
		return table[c][k];

	int& res = table[c][k];
	res = 0;

	for (int t = 0; t <= c; t += coin[k])
	{
		res += calc(c - t, k + 1);
	}

	return res;
}

void solve()
{
	memset(table, -1, sizeof(table));
	coin.clear();

	scanf("%d", &n);

	for (int i = 0; i < n; i++)
	{
		int c;
		scanf("%d", &c);
		coin.push_back(c);
	}

	scanf("%d", &m);

	printf("%d\n", calc(m, 0));
}

int main()
{
	int t;
	scanf("%d", &t);

	for (int i = 0; i < t; i++)
		solve();

	return 0;
}