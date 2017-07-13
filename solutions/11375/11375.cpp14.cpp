#include<stdio.h>
#include<vector>
#include<iostream>
#include<string>
#include<algorithm>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <tuple>
#include <memory.h>
#include <time.h>

int n, m;
int matched[1001];
bool visited[1001];
std::vector<int> edge[1001];


bool dfs(int now)
{
	if (visited[now])
		return false;

	visited[now] = true;

	for (auto& e : edge[now])
	{
		if (matched[e] == 0 || dfs(matched[e]))
		{
			matched[e] = now;
			return true;
		}
	}

	return false;
}

int bmatch()
{
	int ret = 0;

	for (int i = 1; i <= n; i++)
	{
		memset(visited, false, sizeof(visited));

		if (dfs(i))
			ret++;
	}

	return ret;
}

int main()
{
	scanf("%d %d", &n, &m);

	for (int i = 1; i <= n; i++)
	{
		int k;
		scanf("%d", &k);

		for (int j = 0; j < k; j++)
		{
			int job;
			scanf("%d", &job);

			edge[i].push_back(job);
		}
	}

	printf("%d", bmatch());

	return 0;
}