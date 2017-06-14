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
#include <functional>

int d[1001];

std::vector<std::pair<int, int>> edges[1001];

int main()
{
	int n, m;

	scanf("%d %d", &n, &m);

	for (int i = 0; i < m; i++)
	{
		int s, e, c;

		scanf("%d %d %d", &s, &e, &c);

		edges[s].emplace_back(e, c);
	}

	int start, end;
	scanf("%d %d", &start, &end);

	for (int i = 1; i <= n; i++)
		d[i] = 987654321;

	d[start] = 0;

	auto comp = [](std::pair<int, int> l, std::pair<int, int> r)
	{
		return l.first > r.first;
	};

	std::priority_queue<std::pair<int, int>, std::vector<std::pair<int,int>>, decltype(comp)> q(comp);
	std::set<int> s;

	for (int i = 1; i <= n; i++)
		q.emplace(d[i], i);

	while (!q.empty())
	{
		std::pair<int, int> top = q.top();
		q.pop();

		if (top.second == end)
		{
			printf("%d", top.first);
			return 0;
		}

		if (s.find(top.second) != s.end())
			continue;

		s.insert(top.second);

		for (auto& e : edges[top.second])
		{
			if (d[e.first] > d[top.second] + e.second)
			{
				d[e.first] = d[top.second] + e.second;
				q.emplace(d[e.first], e.first);
			}
		}
	}

	return 0;
}