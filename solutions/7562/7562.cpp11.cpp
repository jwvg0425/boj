#include <stdio.h>
#include <queue>
typedef std::pair<int, int> Point;
typedef std::pair<int, Point> Data;

int main()
{
	int t;

	Point move[] =
	{
		Point(-1,-2),
		Point(-1,2),
		Point(1,-2),
		Point(1,2),
		Point(-2,-1),
		Point(-2,1),
		Point(2,-1),
		Point(2,1)
	};

	scanf("%d", &t);

	while (t--)
	{
		bool visited[301][301] = { false, };
		int l;
		Point start;
		Point end;

		scanf("%d", &l);

		scanf("%d %d", &start.first, &start.second);
		scanf("%d %d", &end.first, &end.second);

		std::queue<Data> q;

		q.push(Data(0, start));

		while (!q.empty())
		{
			Data t = q.front();
			q.pop();

			if (visited[t.second.first][t.second.second])
			{
				continue;
			}

			visited[t.second.first][t.second.second] = true;

			if (t.second == end)
			{
				printf("%d\n", t.first);
				break;
			}
			
			for (int i = 0; i < 8; i++)
			{
				Point next = t.second;
				next.first += move[i].first;
				next.second += move[i].second;

				if (next.first < 0 || next.second < 0 ||
					next.first >= l || next.second >= l)
				{
					continue;
				}

				if (!visited[next.first][next.second])
				{
					q.push(Data(t.first + 1, next));
				}
			}
		}
	}


}