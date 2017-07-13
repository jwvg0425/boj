#include <stdio.h>
#include <vector>
#include <algorithm>
#include <memory.h>

std::vector<int> notebook[101];
bool visited[101];
int matched[101];

int n, m;

bool dfs(int now)
{
	if (visited[now])
		return false;

	visited[now] = true;

	for (auto& book : notebook[now])
	{
		if (matched[book] == 0 || dfs(matched[book]))
		{
			matched[book] = now;
			return true;
		}
	}

	return false;
}

int bimatch()
{
	int res = 0;
	for (int i = 1; i <= n; i++)
	{
		memset(visited, false, sizeof(visited));

		if (dfs(i))
			res++;
	}
	return res;
}

int main()
{
	scanf("%d %d", &n, &m);

	for (int i = 0; i < m; i++)
	{
		int a, b;
		scanf("%d %d", &a, &b);

		notebook[a].push_back(b);
	}

	printf("%d", bimatch());

	return 0;
}