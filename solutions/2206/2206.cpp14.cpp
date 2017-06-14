#include<stdio.h>
#include<vector>
#include<iostream>
#include<string>
#include<algorithm>
#include <set>
#include <map>
#include <queue>
#include <tuple>
#include <memory.h>
#define MAX 987654321

using iii = std::tuple<int, int, int>;

int distance[2][1001][1001] = { 0, };

int main()
{
	int n, m;

	scanf("%d %d", &n, &m);

	std::vector<std::string> map;

	for (int i = 0; i < n; i++)
	{
		std::string line;

		std::cin >> line;

		map.push_back(line);
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			distance[0][i][j] = distance[1][i][j] = MAX;
		}
	}


	//(깬 벽, 현재 위치)
	std::queue<iii> q;

	q.emplace(0, 0, 0);
	distance[0][0][0] = 1;

	while (!q.empty())
	{
		int wall, x, y;

		std::tie(wall, x, y) = q.front();

		q.pop();

		int dx[] = { -1,0,1,0 };
		int dy[] = { 0,-1,0,1 };

		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx < 0 || nx >= n || ny < 0 || ny >= m)
				continue;

			if (distance[wall][nx][ny] == MAX && map[nx][ny] != '1')
			{
				distance[wall][nx][ny] = distance[wall][x][y] + 1;
				q.emplace(wall, nx, ny);
			}

			if (wall == 0 && distance[wall + 1][nx][ny] == MAX && map[nx][ny] == '1')
			{
				distance[wall + 1][nx][ny] = distance[wall][x][y] + 1;
				q.emplace(wall + 1, nx, ny);
			}
		}
	}

	int dist = std::min(distance[0][n - 1][m - 1], distance[1][n - 1][m - 1]);

	if (dist == MAX)
	{
		printf("-1");
		return 0;
	}

	printf("%d", dist);

	return 0;
}