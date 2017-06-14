#include <stdio.h>
#include <memory.h>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>

std::vector<int> edges[100001];
int parents[100001];

int main()
{
	int n;
	scanf("%d", &n);

	for (int i = 1; i < n; i++)
	{
		int a, b;
		scanf("%d %d", &a, &b);
		edges[b].push_back(a);
		edges[a].push_back(b);
	}

	parents[1] = -1;

	std::queue<int> q;

	q.push(1);

	while (!q.empty())
	{
		int now = q.front();

		q.pop();

		for (auto& e : edges[now])
		{
			if (parents[e] != 0)
				continue;

			parents[e] = now;

			q.push(e);
		}
	}

	for (int i = 2; i <= n; i++)
		printf("%d\n", parents[i]);

	return 0;
}