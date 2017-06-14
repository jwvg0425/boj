#include <stdio.h>
#include <string>
#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>

void solve()
{
	int color[20001] = { 0, };
	std::vector<int> edges[20001];
	int v, e;

	scanf("%d %d", &v, &e);

	for (int i = 0; i < e; i++)
	{
		int a, b;
		scanf("%d %d", &a, &b);
		edges[a].push_back(b);
		edges[b].push_back(a);
	}

	bool isBipartite = true;

	for (int i = 1; i <= v; i++)
	{
		if (color[i] != 0)
			continue;

		std::queue<int> q;

		color[i] = 1;
		q.push(i);

		while (!q.empty())
		{
			int now = q.front();
			q.pop();

			for (auto& adj : edges[now])
			{
				if (color[adj] == 0)
				{
					color[adj] = 3 - color[now];
					q.push(adj);
				}
				else if (color[adj] == color[now])
				{
					isBipartite = false;
					goto End;
				}
			}
		}
	}

End:

	if (isBipartite)
		printf("YES\n");
	else
		printf("NO\n");
}

int main()
{
	int k;
	scanf("%d", &k);

	for (int i = 0; i < k; i++)
		solve();

	return 0;
}