#include<stdio.h>
#include<vector>
#include<iostream>
#include<string>
#include<algorithm>
#include <set>
#include <queue>
#include <memory.h>

std::vector<int> edges[32001];
int indegree[32001];

int main()
{
	int n, m;
	scanf("%d %d", &n, &m);

	for (int i = 0; i < m; i++)
	{
		int a, b;
		scanf("%d %d", &a, &b);

		edges[a].push_back(b);
	}

	for (int i = 1; i <= n; i++)
	{
		for (auto& e : edges[i])
		{
			indegree[e]++;
		}
	}

	std::queue<int> candidates;

	for (int i = 1; i <= n; i++)
	{
		if (indegree[i] == 0)
			candidates.push(i);
	}

	while (!candidates.empty())
	{
		int now = candidates.front();
		candidates.pop();

		printf("%d ", now);

		for (auto& e : edges[now])
		{
			indegree[e]--;

			if (indegree[e] == 0)
				candidates.push(e);
		}
	}

	return 0;
}