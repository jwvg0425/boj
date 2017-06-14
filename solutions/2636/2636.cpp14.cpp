#include <stdio.h>
#include <algorithm>
#include <queue>

int w, h;
int board[102][102];

//사라진 치즈 조각 개수 리턴
int cheese()
{
	bool visited[102][102] = { false, };

	//가장자리부터 시작해서 탐색 - 만나면 제거
	std::queue<std::pair<int, int>> q;
	int res = 0;

	for (int x = 1; x <= w; x++)
	{
		q.emplace(x, 1);
		q.emplace(x, h);
	}

	for (int y = 2; y < h; y++)
	{
		q.emplace(1, y);
		q.emplace(w, y);
	}

	int dx[] = { -1,0,1,0 };
	int dy[] = { 0,-1,0,1 };

	while (!q.empty())
	{
		auto now = q.front();
		q.pop();

		if (visited[now.first][now.second])
			continue;

		visited[now.first][now.second] = true;

		if (board[now.first][now.second] == 1)
		{
			board[now.first][now.second] = 0;
			res++;
			continue;
		}

		for (int i = 0; i < 4; i++)
		{
			int nx = now.first + dx[i];
			int ny = now.second + dy[i];

			if (nx < 1 || nx > w || ny < 1 || ny > h)
				continue;

			if (!visited[nx][ny])
				q.emplace(nx, ny);
		}
	}

	return res;
}

int main()
{
	scanf("%d %d", &h, &w);

	int num = 0;

	for (int y = 0; y < h; y++)
	{
		for (int x = 0; x < w; x++)
		{
			scanf("%d", &board[x + 1][y + 1]);
			num += board[x + 1][y + 1];
		}
	}

	int time = 0;

	while (true)
	{
		int removed = cheese();
		time++;

		if (num == removed)
			break;

		num -= removed;
	}

	printf("%d\n%d", time, num);

	return 0;
}