#include<stdio.h>
#include<memory.h>
#include <queue>
#include <vector>
#include <algorithm>
#include <string>
#include <iostream>

int main()
{
	int edges[101][101] = { 0, };
	int visit[101];
	memset(visit, -1, sizeof(visit));

	int n, x, y, m;

	scanf("%d %d %d %d", &n, &x, &y, &m);

	for (int i = 0; i < m; i++)
	{
		int c, p;

		scanf("%d %d", &c, &p);

		edges[c][p] = edges[p][c] = 1;
	}

	visit[x] = 0;

	std::queue<int> q;
	q.push(x);

	while (!q.empty())
	{
		int f = q.front();
		q.pop();

		if (f == y)
		{
			printf("%d", visit[f]);
			return 0;
		}

		for (int i = 1; i <= n; i++)
		{
			if (visit[i] == -1 && edges[f][i] == 1)
			{
				visit[i] = visit[f] + 1;
				q.push(i);
			}
		}
	}

	printf("-1");

	return 0;
}