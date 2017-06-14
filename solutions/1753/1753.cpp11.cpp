#include <stdio.h>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <stack>
#include <math.h>
#include <memory.h>
#include <queue>
#include <set>
#define MAX 987654321

struct Edge
{
	Edge(int e, int w) : end(e), weight(w) {}

	int end;
	int weight;
};

std::vector<Edge> edges[20001];
int d[20001];

int main()
{
	int v, e;
	int start;

	scanf("%d %d", &v, &e);
	scanf("%d", &start);

	for (int i = 0; i < e; i++)
	{
		int es, ee, ew;

		scanf("%d %d %d", &es, &ee, &ew);

		edges[es].emplace_back(ee, ew);
	}

	for (int i = 1; i <= v; i++)
	{
		d[i] = MAX;
	}

	d[start] = 0;

	auto comp = [](std::pair<int, int> l, std::pair<int, int> r)
	{
		return l.first > r.first;
	};

	std::priority_queue<std::pair<int, int>, std::vector<std::pair<int,int>>, decltype(comp)> queue(comp);

	for (int i = 1; i <= v; i++)
	{
		queue.emplace(d[i],i);
	}

	std::set<int> s;

	while (!queue.empty())
	{
		int u = queue.top().second;
		queue.pop();

		if (s.find(u) != s.end())
			continue;

		s.insert(u);

		for (auto& e : edges[u])
		{
			if (d[u] + e.weight < d[e.end])
			{
				d[e.end] = d[u] + e.weight;
				queue.emplace(d[e.end], e.end);
			}
		}
	}

	for (int i = 1; i <= v; i++)
	{
		if (d[i] == MAX)
		{
			printf("INF\n");
		}
		else
		{
			printf("%d\n", d[i]);
		}
	}

	return 0;
}