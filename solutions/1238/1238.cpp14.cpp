#include<stdio.h>
#include <queue>
#include <vector>
#define MAX 987654321

int edges[1001][1001];
int n, m, x;

std::vector<int> dijkstra()
{
	std::vector<int> res;
	res.resize(n + 1, MAX);

	auto comp = [](const std::pair<int, int>& l, const std::pair<int, int>& r)
	{
		return l.first > r.first;
	};

	std::priority_queue<std::pair<int, int>, std::vector<std::pair<int,int>>, decltype(comp)> q(comp);

	for (int i = 1; i <= n; i++)
	{
		if (i == x)
			q.emplace(0, i);
		else
			q.emplace(MAX, i);
	}

	while (!q.empty())
	{
		auto top = q.top();
		q.pop();

		if (res[top.second] != MAX)
			continue;

		res[top.second] = top.first;

		for (int i = 1; i <= n; i++)
		{
			if (res[i] > top.first + edges[top.second][i])
			{
				q.emplace(top.first + edges[top.second][i], i);
			}
		}
	}

	return res;
}

int main()
{

	scanf("%d %d %d", &n, &m, &x);

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			edges[i][j] = MAX;

	for (int i = 0; i < m; i++)
	{
		int s, e, w;
		scanf("%d %d %d", &s, &e, &w);
		edges[s][e] = w;
	}

	std::vector<int> a = dijkstra();

	for (int i = 1; i <= n; i++)
		for (int j = i; j <= n; j++)
			std::swap(edges[i][j], edges[j][i]);

	std::vector<int> b = dijkstra();

	int max = 0;

	for (int i = 1; i <= n; i++)
	{
		max = std::max(max, a[i] + b[i]);
	}

	printf("%d", max);


}