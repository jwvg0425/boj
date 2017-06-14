#include <stdio.h>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>
#define MAX 1000000

int n, e;
int edges[801][801];

int dijkstra(int start, int end)
{
	std::queue<int> q;
	int dist[801];
	bool visited[801] = { false, };

	for (int i = 0; i <= n; i++)
	{
		if (i == start)
			dist[i] = 0;
		else
			dist[i] = MAX;
	}

	while (true)
	{
		int minVert = 0;

		for (int i = 1; i <= n; i++)
		{
			if (!visited[i] && dist[i] < dist[minVert])
				minVert = i;
		}

		if (dist[minVert] >= MAX)
			break;

		if (minVert == end)
			break;

		visited[minVert] = true;

		for (int i = 1; i <= n; i++)
		{
			if (dist[i] > dist[minVert] + edges[minVert][i])
			{
				dist[i] = dist[minVert] + edges[minVert][i];
			}
		}
	}

	return dist[end];
}

int main()
{
	scanf("%d %d", &n, &e);

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			edges[i][j] = MAX;

	for (int i = 0; i < e; i++)
	{
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);

		edges[a][b] = std::min(edges[a][b], c);
		edges[b][a] = std::min(edges[b][a], c);
	}

	int u, v;

	scanf("%d %d", &u, &v);

	int mid = dijkstra(u, v);
	int dis = std::min(dijkstra(1, u) + mid + dijkstra(v, n),
		dijkstra(1, v) + mid + dijkstra(u, n));

	if (dis >= MAX)
		printf("-1");
	else
		printf("%d", dis);

	return 0;
}