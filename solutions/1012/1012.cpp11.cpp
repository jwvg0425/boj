#include <stdio.h>
#include <algorithm>
#include <memory.h>
#include <queue>

int dx[] = { -1,0,1,0 };
int dy[] = { 0,-1,0,1 };

void solve()
{
	bool field[52][52] = { false, };
	int m, n, k;

	scanf("%d %d %d", &m, &n, &k);

	for (int i = 0; i < k; i++)
	{
		int x, y;
		scanf("%d %d", &x, &y);

		field[x+1][y+1] = true;
	}

	int count = 0;

	for (int x = 1; x <= m; x++)
	{
		for (int y = 1; y <= n; y++)
		{
			if (!field[x][y])
				continue;

			field[x][y] = false;
			count++;

			std::queue<std::pair<int, int>> q;
			
			q.emplace(x, y);

			while (!q.empty())
			{
				auto top = q.front();
				q.pop();

				for (int i = 0; i < 4; i++)
				{
					auto next = top;
					next.first += dx[i];
					next.second += dy[i];

					if (field[next.first][next.second])
					{
						field[next.first][next.second] = false;
						q.push(next);
					}
				}
			}
		}
	}

	printf("%d\n", count);
}

int main()
{
	int T;

	scanf("%d", &T);

	for (int i = 0; i < T; i++)
	{
		solve();
	}
}