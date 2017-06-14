#include <stdio.h>
#include <memory.h>
#include <algorithm>

int main()
{
	int sum[301][301] = { 0, };
	int n, m;

	scanf("%d %d", &n, &m);

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			int a;
			scanf("%d", &a);

			sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + a;
		}
	}

	int k;

	scanf("%d", &k);

	for (int i = 0; i < k; i++)
	{
		int sx, sy, ex, ey;

		scanf("%d %d %d %d", &sx, &sy, &ex, &ey);

		printf("%d\n", sum[ex][ey] - sum[ex][sy-1] - sum[sx-1][ey] + sum[sx-1][sy-1]);
	}

	return 0;
}