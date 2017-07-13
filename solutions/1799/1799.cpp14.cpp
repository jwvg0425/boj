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

std::vector<int> edges[21];

int n;

//x,y 좌표를 대각선 기준 좌표로 변환
ii convert(ii pos)
{
	int x, y;
	std::tie(x, y) = pos;
	return std::make_pair(x - y + n - 1, x + y);
}

bool visited[21];
int matched[21];

bool dfs(int now)
{
	if (visited[now])
		return false;

	visited[now] = true;

	for (auto& e : edges[now])
	{
		if (matched[e] == -1 || dfs(matched[e]))
		{
			matched[e] = now;
			return true;
		}
	}

	return false;
}

int bimatch()
{
	memset(matched, -1, sizeof(matched));
	int res = 0;

	for (int i = 0; i < 2 * n - 1; i++)
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

	for (int x = 0; x < n; x++)
	{
		for (int y = 0; y < n; y++)
		{
			int k;
			scanf("%d", &k);

			if (k == 0)
				continue;

			ii converted = convert({ x,y });

			edges[converted.first].push_back(converted.second);
		}
	}

	printf("%d", bimatch());

	return 0;
}