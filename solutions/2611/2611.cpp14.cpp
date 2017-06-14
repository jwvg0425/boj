#include <stdio.h>
#include <memory.h>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

int edges[1001][1001];

int main()
{
	int n, m;
	scanf("%d %d", &n, &m);

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
			edges[i][j] = -1;
	}

	for (int i = 0; i < m; i++)
	{
		int p, q, r;

		scanf("%d %d %d", &p, &q, &r);

		edges[p][q] = std::max(edges[p][q], r);
	}

	//0->1로 가는걸로 펴 준다
	for (int i = 1; i <= n; i++)
	{
		edges[0][i] = edges[1][i];
		edges[1][i] = -1;
	}
	int dist[1001] = { 0, };
	int previous[1001] = { 0, };
	bool visited[1001] = { false, };

	dist[0] = -1;

	for (int i = 1; i <= n; i++)
	{
		dist[i] = edges[0][i];
		if (dist[i] == -1)
			dist[i] = 0;
	}

	while(true)
	{
		int min = -1;

		for (int i = 2; i <= n; i++)
		{
			if (visited[i])
				continue;

			if (min == -1 || (dist[i] != 0 && dist[min] > dist[i]))
				min = i;
		}

		if (min == -1)
			break;

		visited[min] = true;

		for (int i = 1; i <= n; i++)
		{
			if (edges[min][i] == -1)
				continue;

			if (dist[i] < dist[min] + edges[min][i])
			{
				dist[i] = dist[min] + edges[min][i];
				previous[i] = min;
				visited[i] = false;
			}
		}
	}

	printf("%d\n", dist[1]);
	std::vector<int> mid;

	mid.push_back(1);
	int now = previous[1];
	while (now != 0)
	{
		mid.push_back(now);
		now = previous[now];
	}
	mid.push_back(1);
	std::reverse(mid.begin(), mid.end());
	for (auto& p : mid)
	{
		printf("%d ", p);
	}

	return 0;
}