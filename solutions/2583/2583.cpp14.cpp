#include <stdio.h>
#include <algorithm>
#include <vector>

int map[101][101] = { 0, };
int m, n, k;

int getArea(int x, int y)
{
	if (x < 0 || y < 0 || x >= n || y >= m)
		return 0;

	if (map[x][y] == 1)
		return 0;

	map[x][y] = 1;

	return 1 + getArea(x - 1, y) + getArea(x, y - 1) + getArea(x + 1, y) + getArea(x, y + 1);
}

int main()
{
	scanf("%d %d %d", &m, &n, &k);

	for (int i = 0; i < k; i++)
	{
		int sx, sy, ex, ey;

		scanf("%d %d %d %d", &sx, &sy, &ex, &ey);

		for (int x = sx; x < ex; x++)
		{
			for (int y = sy; y < ey; y++)
			{
				map[x][y] = 1;
			}
		}
	}

	int count = 0;
	std::vector<int> area;

	for (int x = 0; x < n; x++)
	{
		for (int y = 0; y < m; y++)
		{
			if (map[x][y] == 0)
			{
				count++;
				area.push_back(getArea(x, y));
			}
		}
	}

	std::sort(area.begin(), area.end());

	printf("%d\n", count);
	for (auto& a : area)
		printf("%d ", a);

	return 0;
}