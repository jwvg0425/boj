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

bool visited[201];
int matched[201];

std::vector<int> edges[201];
bool impossible[201][201];

bool dfs(int now)
{
	if (visited[now])
		return false;

	visited[now] = true;

	for (auto& e : edges[now])
	{
		if (matched[e] == 0 || dfs(matched[e]))
		{
			matched[e] = now;
			return true;
		}
	}

	return false;
}

void bimatch(int n)
{
	int count = 0;

	for (int i = 1; i <= n; i++)
	{
		memset(visited, false, sizeof(visited));

		if (dfs(i))
			count++;
	}

	if (count != n)
	{
		printf("-1");
		return;
	}

	for (int i = 1; i <= n; i++)
	{
		printf("%d ", matched[i]);
	}
}

int main()
{
	int n, m;

	scanf("%d %d", &n, &m);

	for (int i = 0; i < m; i++)
	{
		int type, x, y, v;
		scanf("%d %d %d %d", &type, &x, &y, &v);

		for (int j = 1; j <= n; j++)
		{
			if (j < x || j > y)
				impossible[v][j] = true;
			else
				impossible[v][j] |= false;
		}

		if (type == 1)
		{
			for (int j = v + 1; j <= n; j++)
			{
				for (int k = x; k <= y; k++)
				{
					impossible[j][k] = true;
				}
			}
		}
		else
		{
			for (int j = 1; j < v; j++)
			{
				for (int k = x; k <= y; k++)
				{
					impossible[j][k] = true;
				}
			}
		}
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (!impossible[i][j])
				edges[i].push_back(j);
		}
	}

	bimatch(n);


	return 0;
}