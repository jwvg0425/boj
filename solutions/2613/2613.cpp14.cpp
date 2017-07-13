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

using ii = std::pair<int, int>;

std::vector<int> marble = { 0, };

int table[301][301];
int next[301][301];

//0~n까지 구슬들을 m개 그룹으로 나눌때 합 최대의 최소
int solve(int n, int m)
{
	if (m == 1)
	{
		next[n][m] = -1;
		return marble[n + 1];
	}

	if (table[n][m] != -1)
		return table[n][m];

	int& res = table[n][m];
	
	res = std::max(marble[n + 1] - marble[m - 1], solve(m - 2, m - 1));
	next[n][m] = m - 2;

	for (int i = m; i <= n; i++)
	{
		int k = std::max(marble[n + 1] - marble[i], solve(i - 1, m - 1));
		
		if (k < res)
		{
			res = k;
			next[n][m] = i - 1;
		}
	}

	return res;
}

int main()
{
	memset(table, -1, sizeof(table));
	int n, m;

	scanf("%d %d", &n, &m);

	for (int i = 0; i < n; i++)
	{
		int k;
		scanf("%d", &k);
		marble.push_back(marble.back() + k);
	}

	printf("%d\n", solve(n - 1, m));
	std::vector<int> counts;
	int k = n - 1;

	while (m > 0)
	{
		counts.push_back(k - next[k][m]);
		k = next[k][m];
		m--;
	}

	std::reverse(counts.begin(), counts.end());

	for (auto& c : counts)
		printf("%d ", c);

	return 0;
}