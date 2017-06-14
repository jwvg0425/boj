#include<stdio.h>
#include<queue>

int L, W;
char map[51][51];
int max(int a, int b) { return a>b ? a : b; }

int bfs(int x, int y)
{
	std::queue<std::pair<int, int>> q;

	q.emplace(x, y);

	int count[51][51] = { 0, };

	int maxCount = 0;

	count[x][y] = 1;

	while (!q.empty())
	{
		auto top = q.front();
		q.pop();

		maxCount = std::max(maxCount, count[top.first][top.second]);

		int dx[] = { -1,0,1,0 };
		int dy[] = { 0,-1,0,1 };

		for (int i = 0; i < 4; i++)
		{
			int nx = top.first + dx[i];
			int ny = top.second + dy[i];

			if (nx < 0 || ny < 0 || nx >= L || ny >= W)
				continue;

			if (count[nx][ny] != 0)
				continue;

			if (map[nx][ny] != 'L')
				continue;
			
			count[nx][ny] = count[top.first][top.second] + 1;
			q.emplace(nx, ny);
		}
	}

	return maxCount;
}

int main()
{
	int x, y, m = 0;
	scanf("%d %d", &L, &W);
	for (x = 0; x<L; x++)
	{
		scanf("%s", &map[x]);
	}
	for (x = 0; x<L; x++)
	{
		for (y = 0; y<W; y++)
		{
			if (map[x][y] == 'W')
				continue;

			m = max(m, bfs(x, y));
		}
	}
	printf("%d", m - 1);
}