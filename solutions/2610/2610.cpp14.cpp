#include <stdio.h>
#include <algorithm>
#include <queue>
#include <iostream>
#include <bitset>
#include <memory.h>
#include <math.h>

int main()
{
	int edges[101][101] = { 0, };
	int n, m;

	scanf("%d %d", &n, &m);

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (i == j)
				edges[i][j] = 0;
			else
				edges[i][j] = 987654321;
		}
	}

	for (int i = 0; i < m; i++)
	{
		int s, e;

		scanf("%d %d", &s, &e);
		edges[s][e] = edges[e][s] = 1;
	}

	int distance[101] = { 0 , };
	bool visited[101] = { false, };

	for (int k = 1; k <= n; k++)
	{
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				edges[i][j] = std::min(edges[i][j], edges[i][k] + edges[k][j]);
			}
		}
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (edges[i][j] < 987654321)
				distance[i] = std::max(distance[i], edges[i][j]);
		}
	}

	std::vector<int> res;

	for (int i = 1; i <= n; i++)
	{
		if (visited[i])
			continue;

		int min = i;

		for (int j = 1; j <= n; j++)
		{
			if (edges[i][j] < 987654321)
			{
				if (distance[j] < distance[min])
					min = j;

				visited[j] = true;
			}
		}

		res.push_back(min);
	}
	
	std::sort(res.begin(), res.end());

	printf("%d\n", res.size());

	for (auto& r : res)
	{
		printf("%d\n", r);
	}


	return 0;
}