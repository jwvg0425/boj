#include <stdio.h>
#include <vector>
#include <algorithm>
#include <tuple>
#include <map>
#include <set>
#include <iostream>
#include <string>
#include <stack>
#include <queue>
#include <memory.h>

std::vector<int> edges[2001];
bool visited[2001];
int matched[2001];

int n;

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

int bimatch()
{
	int res = 0;

	for (int i = 1; i <= 2 * n; i++)
	{
		memset(visited, false, sizeof(visited));

		if (dfs(i))
			res++;
	}

	return res;
}

int main()
{
	scanf("%d", &n);

	int a[1001];
	int b[1001];
	int c[1001];

	for (int i = 1; i <= n; i++)
	{
		scanf("%d %d %d", &a[i], &b[i], &c[i]);
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (i == j)
				continue;

			if (a[i] < a[j] || b[i] < b[j] || c[i] < c[j])
				continue;

			if (a[i] != a[j] || b[i] != b[j] || c[i] != c[j] || i < j)
			{
				edges[i].push_back(j);
				edges[n + i].push_back(j);
			}
		}
	}

	printf("%d", n - bimatch());

	return 0;
}