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

using ii = std::pair<int, int>;

int n, m;
int map[2][302][302];
int dx[] = { -1,0,1,0 };
int dy[] = { 0,-1,0,1 };

int main()
{
	scanf("%d %d", &n, &m);

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			scanf("%d", &map[0][i][j]);
		}
	}

	for (int time = 1;; time++)
	{
		int prevTime = (time + 1) % 2;

		int nonZero = 0;
	
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= m; j++)
			{
				if (map[prevTime][i][j] == 0)
				{
					map[time % 2][i][j] = 0;
					continue;
				}

				nonZero++;

				int d = 0;

				for (int k = 0; k < 4; k++)
				{
					if (map[prevTime][i + dx[k]][j + dy[k]] == 0)
						d++;
				}

				map[time % 2][i][j] = std::max(0, map[prevTime][i][j] - d);
			}
		}

		if (nonZero == 0)
			break;

		bool visited[302][302] = { false, };

		int count = 0;

		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= m; j++)
			{
				if (map[time % 2][i][j] == 0 || visited[i][j])
					continue;

				count++;

				if (count == 2)
				{
					printf("%d", time);
					return 0;
				}

				std::queue<ii> q;

				visited[i][j] = true;
				q.emplace(i, j);

				while (!q.empty())
				{
					int x, y;

					std::tie(x, y) = q.front();
					q.pop();

					for (int k = 0; k < 4; k++)
					{
						if (map[time % 2][x+dx[k]][y+dy[k]] == 0 || visited[x + dx[k]][y + dy[k]])
							continue;

						visited[x + dx[k]][y + dy[k]] = true;
						q.emplace(x + dx[k], y + dy[k]);
					}
				}
			}
		}
	}

	printf("0");

	return 0;
}