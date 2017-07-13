#include <stdio.h>
#include <vector>
#include <algorithm>
#include <tuple>
#include <map>
#include <set>
#include <iostream>
#include <string>
#include <memory.h>

using ii = std::pair<int, int>;
int r, c, n;
bool visited[301];
int matched[301];
std::vector<int> edges[301];

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

	for (int i = 1; i <= r; i++)
	{
		memset(visited, false, sizeof(visited));

		if (dfs(i))
			res++;
	}

	return res;
}

int board[301][301] = { 0, };

int main()
{
	scanf("%d %d %d", &r, &c, &n);


	for (int i = 0; i < n; i++)
	{
		int x, y;
		scanf("%d %d", &x, &y);

		board[x][y] = 1;
	}

	for (int x = 1; x <= r; x++)
	{
		for (int y = 1; y <= c; y++)
		{
			if (board[x][y] != 0)
				continue;

			edges[x].push_back(y);
		}
	}

	printf("%d", bimatch());

	return 0;
}