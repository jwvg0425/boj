#include<stdio.h>

int spiral[1000][1000] = { 0, };

int main()
{
	int n;
	int find;
	scanf("%d %d", &n, &find);

	spiral[n / 2][n / 2] = 1;
	int sx = n / 2 - 1, sy = n / 2 - 1;
	int fx, fy;
	int val = 2;
	int level = 3;

	int dx[] = { 1,0,-1,0 };
	int dy[] = { 0, 1, 0, -1 };

	while (level <= n)
	{
		for (int d = 0; d < 4; d++)
		{
			for (int i = 0; i < level - 1; i++)
			{
				sx += dx[d];
				sy += dy[d];
				spiral[sy][sx] = val;
				if (val == find)
				{
					fx = sx;
					fy = sy;
				}
				val++;
			}
		}

		level += 2;
		sy--;
		sx--;
	}

	for (int y = 0; y < n; y++)
	{
		for (int x = 0; x < n; x++)
		{
			printf("%d ", spiral[y][x]);
		}
		printf("\n");
	}

	printf("%d %d", fy + 1, fx + 1);

	return 0;
}