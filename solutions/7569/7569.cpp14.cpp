#include<stdio.h>
#include<memory.h>
#include <queue>
#include <vector>
#include <algorithm>
#include <string>
#include <iostream>
#include <tuple>
#define X std::get<0>
#define Y std::get<1>
#define Z std::get<2>

using Pos = std::tuple<int, int, int>;

int map[101][101][101];

int main()
{
	int m, n, h;

	scanf("%d %d %d", &m, &n, &h);

	int totalCount = 0;
	int day = 0;
	std::queue<Pos> q;

	for (int z = 0; z < h; z++)
	{
		for (int y = 0; y < n; y++)
		{
			for (int x = 0; x < m; x++)
			{
				scanf("%d", &map[x][y][z]);

				if (map[x][y][z] == 0)
					totalCount++;
				else if (map[x][y][z] == 1)
					q.emplace(x, y, z);
			}
		}
	}
	
	int dx[] = { -1,0,1,0,0,0 };
	int dy[] = { 0,-1,0,1,0,0 };
	int dz[] = { 0,0,0,0,-1,1 };

	while (!q.empty())
	{
		auto now = q.front();
		q.pop();

		for (int i = 0; i < 6; i++)
		{
			int nx = dx[i] + X(now);
			int ny = dy[i] + Y(now);
			int nz = dz[i] + Z(now);

			if (nx < 0 || ny < 0 || nz < 0 || nx >= m || ny >= n || nz >= h)
				continue;

			if (map[nx][ny][nz] == 0)
			{
				totalCount--;
				map[nx][ny][nz] = map[X(now)][Y(now)][Z(now)] + 1;
				day = std::max(day, map[nx][ny][nz] - 1);
				q.emplace(nx, ny, nz);
			}
		}
	}

	printf("%d", totalCount == 0 ? day : -1);

	return 0;
}