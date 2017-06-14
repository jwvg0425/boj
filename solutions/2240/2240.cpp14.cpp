#include <stdio.h>
#include <algorithm>
#include <queue>
#include <iostream>
#include <bitset>
#include <memory.h>


int table[1001][31][3];
std::vector<int> get;

//t초 시점에서 최대 w번 움직일 수 있을 때, 현재 위치 p인 경우 받을 수 있는 최대량
int solve(int t, int w, int p)
{
	if (t == get.size())
		return 0;

	if (table[t][w][p] != -1)
		return table[t][w][p];

	int& ret = table[t][w][p];

	ret = solve(t + 1, w, p);

	if (w > 0)
	{
		ret = std::max(ret, solve(t + 1, w - 1, 3 - p));
	}

	if (get[t] == p)
	{
		ret++;
	}

	return ret;
}

int main()
{
	int maxT, maxW;

	scanf("%d %d", &maxT, &maxW);

	memset(table, -1, sizeof(table));

	for (int i = 0; i < maxT; i++)
	{
		int p;
		scanf("%d", &p);
		get.push_back(p);
	}

	printf("%d", std::max(solve(0, maxW, 1), solve(0, maxW-1, 2)));

	return 0;
}