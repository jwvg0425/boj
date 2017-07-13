#include <stdio.h>
#include <vector>
#include <algorithm>
#include <tuple>
#include <map>
#include <set>
#include <iostream>
#include <string>
#include <stack>
#include <memory.h>

bool visited[2001];
int matched[1001];

int n, m;
std::vector<int> edges[2001];

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
	int count = 0;

	for (int i = 1; i <= 2 * n; i++)
	{
		memset(visited, false, sizeof(visited));

		if (dfs(i))
			count++;
	}

	return count;
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
			int work;
			scanf("%d", &work);
			edges[i].push_back(work);
			edges[i + n].push_back(work);
		}
	}

	printf("%d", bimatch());

	return 0;
}