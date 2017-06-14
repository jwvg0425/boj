#include<stdio.h>
#include<vector>
#include<iostream>
#include<string>
#include<algorithm>
#include <set>
#include <queue>

int field[101][101];

int main()
{
	int n;
	scanf("%d", &n);
	int maxHeight = 0;

	for (int x = 0; x < n; x++)
	{
		for (int y = 0; y < n; y++)
		{
			scanf("%d", &field[x][y]);
			maxHeight = std::max(maxHeight, field[x][y]);
		}
	}

	int maxCount = 0;

	for (int h = 0; h <= maxHeight; h++)
	{
		bool visited[101][101] = { false, };
		int count = 0;

		std::queue<std::pair<int, int>> q;

		for (int x = 0; x < n; x++)
		{
			for (int y = 0; y < n; y++)
			{
				if (visited[x][y] || field[x][y] <= h)
					continue;

				visited[x][y] = true;
				count++;
				q.emplace(x, y);

				int dx[] = { -1,0,1,0 };
				int dy[] = { 0,-1,0,1 };

				while (!q.empty())
				{
					auto top = q.front();
					q.pop();

					for (int i = 0; i < 4; i++)
					{
						int nx = top.first + dx[i];
						int ny = top.second + dy[i];

						if (nx < 0 || nx >= n || ny < 0 || ny >= n)
							continue;

						if (visited[nx][ny])
							continue;

						if (field[nx][ny] <= h)
							continue;

						visited[nx][ny] = true;
						q.emplace(nx, ny);
					}
				}
			}
		}

		maxCount = std::max(maxCount, count);
	}

	printf("%d", maxCount);

	return 0;
}