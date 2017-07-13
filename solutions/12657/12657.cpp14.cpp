#include <stdio.h>
#include <string>
#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>
#include <memory.h>
#include <memory>
#include <time.h>
#include <tuple>

using ii = std::pair<int, int>;

void solve()
{
	int w, h;
	scanf("%d %d", &w, &h);

	int maps[102][102] = { 0, };
	int areas[101][101] = { 0, };
	int sinkIdx = 1;
	char labels[27] = { 0, };

	//boundary setting
	for (int x = 0; x <= w + 1; x++)
	{
		maps[x][0] = 10001;
		maps[x][h + 1] = 10001;
	}

	for (int y = 0; y <= h + 1; y++)
	{
		maps[0][y] = 10001;
		maps[w + 1][y] = 10001;
	}

	for (int x = 1; x <= w; x++)
	{
		for (int y = 1; y <= h; y++)
		{
			scanf("%d", &maps[x][y]);
		}
	}

	//sink부터 찾아서 만들어놓는다
	for (int x = 1; x <= w; x++)
	{
		for (int y = 1; y <= h; y++)
		{
			if (maps[x - 1][y] >= maps[x][y] && maps[x + 1][y] >= maps[x][y] &&
				maps[x][y - 1] >= maps[x][y] && maps[x][y + 1] >= maps[x][y])
			{
				areas[x][y] = sinkIdx;
				sinkIdx++;
			}
		}
	}

	//이제 area 안 채워져있는 애들에 대해 sink 기준으로 area 채운다
	for (int x = 1; x <= w; x++)
	{
		for (int y = 1; y <= h; y++)
		{
			int nx = x, ny = y;
			std::vector<ii> path;

			while (areas[nx][ny] == 0)
			{
				path.emplace_back(nx, ny);

				std::vector<ii> lows;

				if (maps[nx - 1][ny] < maps[nx][ny])
					lows.emplace_back(nx - 1, ny);

				if (maps[nx][ny - 1] < maps[nx][ny])
					lows.emplace_back(nx, ny - 1);

				if (maps[nx][ny + 1] < maps[nx][ny])
					lows.emplace_back(nx, ny + 1);

				if (maps[nx + 1][ny] < maps[nx][ny])
					lows.emplace_back(nx + 1, ny);

				int lowx = lows[0].first, lowy = lows[0].second;

				for (int i = 1; i < lows.size(); i++)
				{
					int lx, ly;

					std::tie(lx, ly) = lows[i];
					if (maps[lowx][lowy] > maps[lx][ly])
					{
						lowx = lx;
						lowy = ly;
					}
				}

				nx = lowx;
				ny = lowy;
			}

			for (auto& p : path)
			{
				areas[p.first][p.second] = areas[nx][ny];
			}
		}
	}

	char l = 'a';

	//이제 여기서 각 area에 대한 라벨링
	for (int x = 1; x <= w; x++)
	{
		for (int y = 1; y <= h; y++)
		{
			int area = areas[x][y];

			if (labels[area] != 0)
				continue;

			labels[area] = l;
			l++;
		}
	}

	for (int x = 1; x <= w; x++)
	{
		for (int y = 1; y <= h; y++)
		{
			int area = areas[x][y];
			printf("%c ", labels[area]);
		}
		printf("\n");
	}
}

int main()
{
	int t;
	scanf("%d", &t);

	for (int i = 1; i <= t; i++)
	{
		printf("Case #%d:\n", i);
		solve();
	}

	return 0;
}