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
int main()
{
	int n, m;
	int edges[101][101] = { 0, };

	scanf("%d %d", &n, &m);

	for (int i = 0; i < m; i++)
	{
		int a, b;
		scanf("%d %d", &a, &b);

		edges[a][b] = 1;
	}

	//floyd로 모든 쌍에 대해 갈 수 있는 곳 찾기
	for (int k = 1; k <= n; k++)
	{
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				edges[i][j] = std::max(edges[i][j], edges[i][k] * edges[k][j]);
			}
		}
	}

	for (int i = 1; i <= n; i++)
	{
		int count = 0;
        edges[i][i] = 1;

		for (int j = 1; j <= n; j++)
		{
			if (edges[i][j] == 0 && edges[j][i] == 0)
				count++;
		}
		printf("%d\n", count);
	}

	return 0;
}