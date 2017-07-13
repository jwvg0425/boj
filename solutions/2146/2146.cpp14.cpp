#include <stdio.h>
#include <vector>
#include <algorithm>
#include <tuple>
#include <map>
#include <set>
#include <iostream>
#include <string>
#include <stack>
#include <queue>
#include <memory.h>

int n;
int map[101][101];
int dx[] = { -1,0,1,0 };
int dy[] = { 0,-1,0,1 };

void fill(int x, int y, int num)
{
	map[x][y] = num;

	for (int k = 0; k < 4; k++)
	{
		int nx = x + dx[k];
		int ny = y + dy[k];

		if (nx < 0 || nx >= n || ny < 0 || ny >= n)
			continue;

		if (map[nx][ny] != 1)
			continue;

		fill(nx, ny, num);
	}
}

void numbering()
{
	int number = 2;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (map[i][j] == 1)
			{
				fill(i, j, number);
				number++;
			}
		}
	}
}

int count()
{
	int distance[101][101] = { 0, };

	int d = 0;

	while (true)
	{
		bool find = false;
		int min = n*n;

		for (int x = 0; x < n; x++)
		{
			for (int y = 0; y < n; y++)
			{
				if (map[x][y] == 0)
					continue;

				if (distance[x][y] != d)
					continue;

				for (int i = 0; i < 4; i++)
				{
					int nx = x + dx[i];
					int ny = y + dy[i];

					if (nx < 0 || nx >= n || ny < 0 || ny >= n)
						continue;

					if (map[nx][ny] == map[x][y])
						continue;

					if (map[nx][ny] != 0)
					{
						find = true;
						min = std::min(min, distance[nx][ny] + distance[x][y]);
					}

					map[nx][ny] = map[x][y];
					distance[nx][ny] = d + 1;
				}
			}
		}

		if (find)
			return min;

		d++;
	}

	return 0;
}

int main()
{
	scanf("%d", &n);

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			scanf("%d", &map[i][j]);

	numbering();

	printf("%d", count());

	return 0;
}