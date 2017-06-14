#include <stdio.h>
#include <memory.h>
#include <algorithm>
#include <queue>

int main()
{
	int n, m;
	int miro[102][102] = { 0, };
	int dist[102][102] = { 0, };

	scanf("%d %d", &n, &m);

	for (int i = 1; i <= n; i++)
	{
		char buffer[200];
		scanf("%s", buffer);

		for (int j = 1; j <= m; j++)
		{
			miro[i][j] = buffer[j - 1] - '0';
		}
	}

	std::queue<std::pair<int, int>> q;

	q.emplace(1, 1);
	dist[1][1] = 1;

	while (!q.empty())
	{
		auto top = q.front();
		q.pop();

		if (top.first == n && top.second == m)
		{
			printf("%d", dist[top.first][top.second]);
			return 0;
		}

		int dx[] = { -1, 0, 1, 0 };
		int dy[] = { 0, -1, 0, 1 };

		for (int i = 0; i < 4; i++)
		{
			std::pair<int, int> now;
			now.first = top.first + dx[i];
			now.second = top.second + dy[i];

			if (miro[now.first][now.second] != 0 
				&& dist[now.first][now.second] == 0)
			{
				dist[now.first][now.second] =
					dist[top.first][top.second] + 1;

				q.emplace(now.first, now.second);
			}
		}
	}
}