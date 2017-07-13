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

//edges[k] = k번 노드 자식들, (c,w) c 자식 w 간선
std::vector<ii> edges[100001];
int dist[100001];
bool visited[100001];
int n;

//(end, dist) start에서 제일 먼 end, 그 뒤는 거리 dist
ii bfs(int start)
{
	std::fill(dist, dist + n + 1, 0);
	std::fill(visited, visited + n + 1, false);

	std::queue<int> q;

	q.push(start);

	visited[start] = true;

	int maxDist = 0;

	while (!q.empty())
	{
		int now = q.front();
		q.pop();

		for (auto& e : edges[now])
		{
			int next, weight;
			std::tie(next, weight) = e;

			if (visited[next])
				continue;

			visited[next] = true;

			dist[next] = dist[now] + weight;
			maxDist = std::max(maxDist, dist[next]);

			q.push(next);
		}
	}

	for (int i = 1; i <= n; i++)
	{
		if (dist[i] == maxDist)
			return std::make_pair(i, maxDist);
	}
}

int main()
{
	scanf("%d", &n);

	for (int i = 0; i < n; i++)
	{
		int p;

		scanf("%d", &p);

		while (true)
		{
			int c, w;

			scanf("%d", &c);

			if (c == -1)
				break;

			scanf("%d", &w);

			edges[p].emplace_back(c, w);
		}
	}

	ii mid = bfs(1);
	ii end = bfs(mid.first);

	printf("%d", end.second);

	return 0;
}