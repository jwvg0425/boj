#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <string>
#include <memory.h>
#include <map>
#include <vector>
#include <set>
#include <queue>
#include <stack>
#include <math.h>
#include <deque>

int dx[] = { -1,0,1,0 };
int dy[] = { 0,-1,0,1 };

int getCount(std::vector<std::string> map)
{
	int count = 0;

	for (int x = 0; x < map.size(); x++)
	{
		for (int y = 0; y < map.size(); y++)
		{
			if (map[x][y] == 'X')
			{
				continue;
			}

			char c = map[x][y];
			std::queue<std::pair<int, int>> q;

			q.emplace(x, y);

			while (!q.empty())
			{
				int sx, sy;
				std::tie(sx, sy) = q.front();
				q.pop();

				for (int i = 0; i < 4; i++)
				{
					int nx = sx + dx[i];
					int ny = sy + dy[i];

					if (nx < 0 || nx >= map.size() || ny < 0 || ny >= map.size())
						continue;

					if (map[nx][ny] == 'X')
						continue;

					if (map[nx][ny] != c)
						continue;

					map[nx][ny] = 'X';

					q.emplace(nx, ny);
				}
			}

			count++;
		}
	}

	return count;
}

int main()
{
	std::vector<std::string> map;

	int n;
	scanf("%d", &n);

	for (int i = 0; i < n; i++)
	{
		std::string str;

		std::cin >> str;

		map.push_back(str);
	}

	int normal = getCount(map);

	for (auto& l : map)
	{
		for (auto& c : l)
		{
			if (c == 'G')
				c = 'R';
		}
	}

	int redgreen = getCount(map);

	printf("%d %d", normal, redgreen);

	return 0;
}