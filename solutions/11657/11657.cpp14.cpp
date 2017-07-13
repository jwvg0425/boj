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
#define INF 987654321

using iii = std::tuple<int, int, int>;

std::vector<iii> edges;
int distance[501];

int main()
{
	std::fill(distance, distance + 501, INF);
	int n, m;
	scanf("%d %d", &n, &m);

	for (int i = 0; i < m; i++)
	{
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);

		edges.emplace_back(a, b, c);
	}

	distance[1] = 0;

	for (int i = 1; i <= n; i++)
	{
		for (auto& e : edges)
		{
			int s, d, w;

			std::tie(s, d, w) = e;

			distance[d] = std::min(distance[d], distance[s] + w);
		}
	}

	for (auto& e : edges)
	{
		int s, d, w;

		std::tie(s, d, w) = e;

		if (distance[d] > distance[s] + w)
		{
			printf("-1");
			return 0;
		}
	}

	for (int i = 2; i <= n; i++)
	{
		printf("%d\n", distance[i] == INF ? -1 : distance[i]);
	}

	return 0;
}