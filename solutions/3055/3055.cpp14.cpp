#include <stdio.h>
#include <algorithm>
#include <queue>
#include <iostream>
#include <string>

std::vector<std::string> map;

struct Node
{
	Node(int x_, int y_, char c_, int t = 0) : x(x_), y(y_), c(c_), time(t) {}

	int x, y;
	int time = 0;
	char c;
};

int main()
{
	int r, c;
	scanf("%d %d", &r, &c);

	std::queue<Node> q;
	int sx,sy;

	for (int y = 0; y < r; y++)
	{
		std::string line;

		std::cin >> line;

		map.push_back(line);

		for (int x = 0; x < c; x++)
		{
			if (map[y][x] == '*')
				q.emplace(x, y, map[y][x]);

			if (map[y][x] == 'S')
			{
				sx = x;
				sy = y;
			}
		}
	}

	//고슴도치는 맨 마지막에(물 찰 예정인 곳 못 가는 규칙 만족용)
	q.emplace(sx, sy, 'S');

	int dx[] = { -1,0,1,0 };
	int dy[] = { 0,-1,0,1 };

	while (!q.empty())
	{
		auto now = q.front();
		q.pop();

		if (map[now.y][now.x] == 'D' && now.c == 'S')
		{
			printf("%d", now.time);
			return 0;
		}

		for (int i = 0; i < 4; i++)
		{
			int nx = now.x + dx[i];
			int ny = now.y + dy[i];

			if (nx < 0 || nx >= c || ny < 0 || ny >= r)
				continue;

			if (map[ny][nx] == '.')
			{
				map[ny][nx] = now.c;
				q.emplace(nx, ny, now.c, now.time + 1);
			}

			if (map[ny][nx] == 'S' && now.c == '*')
			{
				map[ny][nx] = now.c;
				q.emplace(nx, ny, now.c, now.time + 1);
			}

			if (map[ny][nx] == 'D' && now.c == 'S')
				q.emplace(nx, ny, now.c, now.time + 1);
		}
	}

	printf("KAKTUS");

	return 0;
}