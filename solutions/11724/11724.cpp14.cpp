#include <stdio.h>
#include <algorithm>
#include <queue>

bool visited[1001] = { false, };
int edges[1001][1001];

int main()
{
	int n, m;
	int components = 0;

	scanf("%d %d", &n, &m);

	for (int i = 0; i < m; i++)
	{
		int u, v;
		scanf("%d %d", &u, &v);

		edges[u][v] = edges[v][u] = 1;
	}

	for (int i = 1; i <= n; i++)
	{
		if (visited[i])
			continue;

		std::queue<int> q;

		q.push(i);
		visited[i] = true;

		while (!q.empty())
		{
			int now = q.front();
			q.pop();

			for (int adj = 1; adj <= n; adj++)
			{
				if (edges[now][adj] == 1 && !visited[adj])
				{
					q.push(adj);
					visited[adj] = true;
				}
			}
		}

		components++;
	}

	printf("%d", components);

	return 0;
}