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

int main()
{
	int n, m;
	int map[101][101];

	scanf("%d %d", &m, &n);

	int minCount[101][101] = { 0, };

	for (int y = 0; y < n; y++)
	{
		std::string str;
		std::cin >> str;

		for (int x = 0; x < m; x++)
		{
			map[x][y] = str[x] - '0';
			minCount[x][y] = 987654321;
		}
	}

	std::queue<std::tuple<int, int, int>> q;

	q.emplace(0, 0, 0);

	int dx[] = { -1,0,1,0 };
	int dy[] = { 0,-1,0,1 };

	minCount[0][0] = 0;

	while (!q.empty())
	{
		int x, y, d;
		std::tie(x, y, d) = q.front();
		q.pop();

		if (d > minCount[x][y])
			continue;

		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx < 0 || nx >= m || ny < 0 || ny >= n)
				continue;

			if (minCount[nx][ny] <= minCount[x][y] + map[nx][ny])
				continue;

			minCount[nx][ny] = minCount[x][y] + map[nx][ny];

			q.emplace(nx, ny, minCount[nx][ny]);
		}
	}

	printf("%d", minCount[m - 1][n - 1]);

	return 0;
}